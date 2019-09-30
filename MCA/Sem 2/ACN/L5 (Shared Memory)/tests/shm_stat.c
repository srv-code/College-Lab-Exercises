/* For testing: IPC_STAT using shmctl() */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wait.h>


int main(const int argc, const char *argv[]) {
	const char* sh_resc = "sourav dey";
	const int sh_resc_len = strlen(sh_resc);
	const int shmsz = sh_resc_len;

	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		fprintf(stderr, "  {Main proc:    Err: ftok failed (%s)} \n", strerror(errno));
		exit(1);
	}	
	printf("  [Main proc:    shmkey=0x%x] \n", shmkey);
	
	int forkstat = fork();
	if(forkstat == -1) {
		fprintf(stderr, "  {Main proc:    Err: fork failed (%s)} \n", strerror(errno));
		exit(1);
	}

	if(forkstat == 0) { // child proc
		printf("  [Child proc:   sleeping...] \n");
		sleep(3); 
		printf("  [Child proc:   woke up] \n");
	
		// get shmid: no CREATE operation, so no flag
		int shmid = shmget(shmkey, sh_resc_len, 0);
		if(shmid == -1) {
			fprintf(stderr, "  {Child proc:   Err: shmget failed (%s)} \n", strerror(errno));
			exit(1);
		}
		printf("  [Child proc:   shmid=%d] \n", shmid);
		
		// attach shm seg 
		printf("  [Child proc:   Attaching as read-only shm seg...] \n");
		char* shmaddr = (char*) shmat(shmid, NULL, SHM_RDONLY);
		if(shmaddr == (char*)-1) {
			fprintf(stderr, "  {Child proc:   Err: shmat failed (%s)} \n", strerror(errno));
			exit(1);
		}
		printf("  [Child proc:   shmaddr=%p] \n", (void*) shmaddr);
		
		printf("  [Child proc:   sleeping...] \n");
		sleep(3); 
		printf("  [Child proc:   woke up] \n");
		
		struct shmid_ds info_buf;
		if(shmctl(shmid, IPC_STAT, &info_buf) == -1) {
			fprintf(stderr, "  {Child proc:   Err: shmctl using IPC_STAT failed (%s)} \n", strerror(errno));
			exit(1);
		}
		printf("Child proc: shmid_ds struct info: \n");
		printf("  shm_segsz=%lu \n", info_buf.shm_segsz);
		printf("  shm_nattch=%lu \n", info_buf.shm_nattch);
		printf("\n");
		
		// write shm seg contents to stdout 
		printf("Child proc:   sh resc='%s' \n", shmaddr);
		
		// detach shm seg from child 
		printf("  [Child proc:   Detaching shm seg...] \n");
		if(shmdt(shmaddr) == -1) {
			fprintf(stderr, "  {Child proc:   Err: shmdt failed (%s)} \n", strerror(errno));
			exit(1);
		}
		
		printf("  [Child proc:   finishing...] \n");

	} else { // parent proc
		// get shmid: ensure creation of shm seg
		int shmid = shmget(shmkey, sh_resc_len, 0666 | IPC_CREAT | IPC_EXCL);
		if(shmid == -1) {
			fprintf(stderr, "  {Parent proc:  Err: shmget failed (%s)} \n", strerror(errno));
			exit(1);
		}
		printf("  [Parent proc:  shmid=%d] \n", shmid);
		
		// attach seg 
		printf("  [Parent proc:  Attaching shm seg...] \n");
		char* shmaddr = (char*) shmat(shmid, NULL, 0);
		if(shmaddr == (char*)-1) {
			fprintf(stderr, "  {Parent proc:  Err: shmat failed (%s)} \n", strerror(errno));
			exit(1);
		}
		printf("  [Parent proc:  shmaddr=%p] \n", (void*) shmaddr);
		
		// put resc in shm seg 
		printf("  [Parent proc:  Copying sh resc to shm seg...] \n");
		// strcpy(shmaddr, sh_resc);
		for(int i=0; i<sh_resc_len; i++)
			shmaddr[i] = sh_resc[i];
		shmaddr[sh_resc_len] = 0; // setting EOS
		
		// wait for child proc to finish
		printf("  [Parent proc:  Waiting for child proc to finish...] \n");
		wait(NULL);
		printf("  [Parent proc:  child finished execution] \n");
		
		// detach shm seg 
		printf("  [Parent proc:  Detaching shm seg...] \n");
		if(shmdt(shmaddr) == -1) {
			fprintf(stderr, "  {Parent proc:  Err: shmdt failed (%s)} \n", strerror(errno));
			exit(1);
		}
		
		// remove shm seg 
		printf("  [Parent proc:  Removing shm seg...] \n");
		if(shmctl(shmid, IPC_RMID, NULL) == -1) {
			fprintf(stderr, "  {Parent proc:  Err: shmctl failed (%s)} \n", strerror(errno));
			exit(1);
		}
		
		printf("  [Parent proc:  finishing...] \n");
	}

	return 0;
}

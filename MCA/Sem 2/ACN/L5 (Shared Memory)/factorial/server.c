/* 14) The client stores an operator and corresponding 
		operands in a shared memory. These contents are 
		read by the server and the result is processed 
		and returned back to the client accordingly.
		
	>> Server module 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "globals.c"


int fact(int num) {
	int fact = num;
	while(--num > 0) {
		fact *= num;
	}
	
	return fact;
}

int main() {
	/* create shmkey */
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		fprintf(stderr, "Err in server: Cannot generate shm key (ftok: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* create & get shm seg id: ensure new shm seg creation */
	int shmid = shmget(shmkey, SHMSZ, 0666 | IPC_CREAT | IPC_EXCL);
	if(shmid == -1) {
		fprintf(stderr, "Err in server: Cannot generate shm ID (shmget: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* attach shm seg to this proc addr space */
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		fprintf(stderr, "Err in server: Cannot attach shm seg to server process (shmat: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Server started] \n");
	while(shmaddr[0] != SIG_STOP) {
		if(shmaddr[0] == SIG_EXEC) {
			for(int startidx=1, n=startidx, f=ELECNT+startidx; n<ELECNT+startidx; n++, f++) {
				shmaddr[f] = fact(shmaddr[n]);
			}
			shmaddr[0] = SIG_DONE;
		}
		sleep(1);
	}

	/* detach shm seg from this proc addr space */
	if(shmdt(shmaddr) == -1) {
		fprintf(stderr, "Err in server: Cannot detach shm seg from server process (shmdt: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* remove shm seg */
	if(shmctl(shmid, IPC_RMID, NULL) == -1) {
		fprintf(stderr, "Err in server: Cannot remove shm seg from server process (shmctl: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Server shutting down...] \n");
	
	
	return 0;
}
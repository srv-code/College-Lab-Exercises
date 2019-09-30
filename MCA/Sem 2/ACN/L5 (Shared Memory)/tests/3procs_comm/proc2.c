/* 3 processes communicating via shm */
/* Proc 2 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wait.h>

int main() {
	printf("[proc2: started] \n");
	size_t shmsz = 2; // one for signal bit & another for int content
	
	/* help in generating same key for all processes 
		from same dir, with same proj id */
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		printf("[proc2: ftok failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	int shmid = shmget(shmkey, shmsz, 0666);
	if(shmid == -1) {
		printf("[proc2: shmget failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		printf("[proc2: shmat failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	shmaddr[1] = 22; // putting content
	shmaddr[0] = 2; // setting signal bit
	printf("[proc2: mem value set] \n");
	
	
	if(shmdt(shmaddr) == -1) {
		printf("[proc2: shmdt failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	printf("[proc2 exiting...] \n");
	
	return 0;
}

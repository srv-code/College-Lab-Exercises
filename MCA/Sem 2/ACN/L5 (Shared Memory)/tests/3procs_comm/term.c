/* 3 processes communicating via shm */
/* Terminating proc: sets the stop signal bit, doesn't put any value */

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
	printf("[term: started] \n");
	size_t shmsz = 2; // one for signal bit & another for int content
	
	/* help in generating same key for all processes 
		from same dir, with same proj id */
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		printf("[term: ftok failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	int shmid = shmget(shmkey, shmsz, 0666);
	if(shmid == -1) {
		printf("[term: shmget failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		printf("[term: shmat failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	shmaddr[0] = -1; // setting signal bit to stop value
	printf("[term: mem value set] \n");
	
	
	if(shmdt(shmaddr) == -1) {
		printf("[term: shmdt failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	printf("[term exiting...] \n");
	
	return 0;
}

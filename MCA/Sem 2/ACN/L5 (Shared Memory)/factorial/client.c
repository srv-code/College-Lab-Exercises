/* 14) The client stores an operator and corresponding 
		operands in a shared memory. These contents are 
		read by the server and the result is processed 
		and returned back to the client accordingly.
		
	>> Client module 
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


int main() {
	/* create shmkey */
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		fprintf(stderr, "Server-side error: Cannot generate shm key (ftok: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* fetch shm seg id: don't attempt to create */
	int shmid = shmget(shmkey, SHMSZ, 0666);
	if(shmid == -1) {
		fprintf(stderr, "Server-side error: Cannot generate shm ID (shmget: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* attach shm seg to this proc addr space */
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		fprintf(stderr, "Server-side error: Cannot attach shm seg to client process (shmat: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Client started] \n");
	
	// Filling client side data
	printf("Enter inputs: \n");
	for(int startidx=1, i=startidx; i<ELECNT+startidx; i++) {
		printf("  Integer %d:  ", i);
		scanf("%d", &shmaddr[i]);
	}
	shmaddr[0] = SIG_EXEC; // signal to server for processing
	
	while(shmaddr[0] != SIG_DONE)  { // waiting for server to respond
		sleep(1);
	}
	shmaddr[0] = SIG_STOP; // signal to server to stop 
	
	printf("Results: \n");
	for(int startidx=1, n=startidx, f=ELECNT+startidx; n<ELECNT+startidx; n++, f++) {
		printf("  fact(%d)=%d \n", shmaddr[n], shmaddr[f]);
	}

	/* detach shm seg from this proc addr space */
	if(shmdt(shmaddr) == -1) {
		fprintf(stderr, "Server-side error: Cannot detach shm seg from client process (shmdt: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Client exiting...] \n");
	
	
	return 0;
}

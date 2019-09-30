#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "globals.h"


int main() {
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		fprintf(stderr, "Server-side error: Cannot generate shm key (ftok: %s) \n", strerror(errno));
		exit(1);
	}
	
	int shmid = shmget(shmkey, SHMSZ, 0666);
	if(shmid == -1) {
		fprintf(stderr, "Server-side error: Cannot generate shm ID (shmget: %s) \n", strerror(errno));
		exit(1);
	}
	
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		fprintf(stderr, "Server-side error: Cannot attach shm seg to client process (shmat: %s) \n", strerror(errno));
		exit(1);
	}
	
    int m=2, n=3;
    int matr[m][n];
	printf("[Client started] \n");
    for(int i=0, k=1, no; i<m; i++) {
        for(int j=0; j<n; j++, k++) {
            no=k*11;
            printf("%2d  ", no);
            matr[m][n] = no;
        }
        printf("\n");
    }
    printf("\n");
    shmaddr[1] = (int)matr;
    printf("written to shmaddr[1]: %p \n", (int*)matr);

	shmaddr[0] = SIG_EXEC;	
	while(shmaddr[0] != SIG_DONE)  {
		sleep(1);
	}
	shmaddr[0] = SIG_STOP;

	if(shmdt(shmaddr) == -1) {
		fprintf(stderr, "Client-side error: Cannot detach shm seg from client process (shmdt: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Client exiting...] \n");
	
	
	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include "globals.h"


void matfill(const int m, const int n, int offset, int* paddr) {
    for(int  i=0; i<m; i++) {
        printf("  Row %d: \n", i+1);
        for(int j=0; j<n; j++, offset++) {
            printf("    Column %d:  ", j+1);
            scanf("%d", paddr+offset);
        }
    }
    printf("\n");
}

void matshow(const int m, const int n, int offset, int* paddr) {
    for(int  i=0; i<m; i++) {
        for(int j=0; j<n; j++, offset++) {
            printf("%2d  ", *(paddr+offset));
        }
        printf("\n");
    }
    printf("\n");
}

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
	
	printf("[Client started] \n");

    int m, n, idx=0;
    printf("Enter matrix dimensions [m*n]:  ");
    scanf("%d %d", &m, &n);

    idx++;
    shmaddr[idx++] = m;
    shmaddr[idx++] = n;

    printf("Enter for matrix 1: \n");
    matfill(m, n, idx, shmaddr);

    idx += m*n;
    printf("Enter for matrix 2: \n");
    matfill(m, n, idx, shmaddr);

    idx = 3;
    printf("Matrix 1: \n");
    matshow(m, n, idx, shmaddr);

    idx += m*n;
    printf("Matrix 2: \n");
    matshow(m, n, idx, shmaddr);

	shmaddr[0] = SIG_EXEC;	
	while(shmaddr[0] != SIG_DONE)  {
		sleep(1);
	}
	shmaddr[0] = SIG_STOP;

    printf("Summation matrix: \n");    
    matshow(m, n, 3+(2*m*n), shmaddr);

	if(shmdt(shmaddr) == -1) {
		fprintf(stderr, "Client-side error: Cannot detach shm seg from client process (shmdt: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Client exiting...] \n");
	
	
	return 0;
}

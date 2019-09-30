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


int calc_arith(	const int operator, 
				const int operand1, 
				const int operand2) {
	switch(operator) {
		case '+':
			return operand1+operand2;
			
		case '-':
			return operand1-operand2;
		
		case '*':
			return operand1*operand2;
		
		case '/':
			return operand1/operand2;
			
		default: 
			fprintf(stderr, "Server-side error: Invalid operator value (%d)! \n", operator);
			exit(1);
	}
}

int main() {
	/* create shmkey */
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		fprintf(stderr, "Server-side error: Cannot generate shm key (ftok: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* create & get shm seg id: ensure new shm seg creation */
	int shmid = shmget(shmkey, SHMSZ, 0666 | IPC_CREAT | IPC_EXCL);
	if(shmid == -1) {
		fprintf(stderr, "Server-side error: Cannot generate shm ID (shmget: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* attach shm seg to this proc addr space */
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		fprintf(stderr, "Server-side error: Cannot attach shm seg to server process (shmat: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Server started] \n");
	while(shmaddr[0] != SIG_STOP) {
		if(shmaddr[0] == SIG_EXEC) {
			shmaddr[4] = calc_arith(shmaddr[1], shmaddr[2], shmaddr[3]);
			shmaddr[0] = SIG_DONE;
		}
		sleep(1);
	}

	/* detach shm seg from this proc addr space */
	if(shmdt(shmaddr) == -1) {
		fprintf(stderr, "Server-side error: Cannot detach shm seg from server process (shmdt: %s) \n", strerror(errno));
		exit(1);
	}
	
	/* remove shm seg */
	if(shmctl(shmid, IPC_RMID, NULL) == -1) {
		fprintf(stderr, "Server-side error: Cannot remove shm seg from server process (shmctl: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("[Server shutting down...] \n");
	
	
	return 0;
}

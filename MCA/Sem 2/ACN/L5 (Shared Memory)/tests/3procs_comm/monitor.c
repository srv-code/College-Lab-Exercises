/* 3 processes communicating via shm */
/* Monitoring proc */

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
	size_t shmsz = 2; // one for signal bit & another for int content
	
	/* help in generating same key for all processes 
		from same dir, with same proj id */
	key_t shmkey = ftok(".", 'a');
	if(shmkey == -1) {
		printf("[monitor: ftok failed: %s] \n", strerror(errno));
		exit(1);
	}
	printf("[monitor: shmkey=0x%x] \n", shmkey);
	
	int shmid = shmget(shmkey, shmsz, 0666|IPC_CREAT|IPC_EXCL);
	if(shmid == -1) {
		printf("[monitor: shmget failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	int* shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (int*)-1) {
		printf("[monitor: shmat failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	shmaddr[0] = 0; // reset signal bit
	
	printf("[monitor: started monitoring actvities] \n");
	const int stop_signal_value = -1;
	int next_signal_value = 1;
	while(shmaddr[0] != stop_signal_value) { // will check for signal bit in ascending order
		if(shmaddr[0] == next_signal_value) {
			printf("[monitor: proc put msg: msg=%d] \n", shmaddr[1]);
			next_signal_value++;
		}
		
		sleep(1);
	}
	printf("[monitor: got all reqd activities, preparing to shutdown...] \n");
	
	if(shmdt(shmaddr) == -1) {
		printf("[monitor: shmdt failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	if(shmctl(shmid, IPC_RMID, NULL) == -1) {
		printf("[monitor: shmctl failed: %s] \n", strerror(errno));
		exit(1);
	}
	
	printf("[monitor exiting...] \n");
	
	return 0;
}

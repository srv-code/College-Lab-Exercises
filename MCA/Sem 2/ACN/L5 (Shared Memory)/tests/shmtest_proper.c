#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


struct pack {
	int op1, op2;
	int arr[3][2];
	float res, arrsum;
	int req, done, stop;
};

int init_cli() {
	printf("client started \n");

	key_t key = ftok(".", 'a');
	if(key == -1) {
		printf("ftok err \n");
		return 1;
	}

	int shmid = shmget(key, sizeof(struct pack), 0666);
	if(shmid == -1) {
		printf("shmget err: %s \n", strerror(errno));
		return 1;
	}

	struct pack* shmaddr = (struct pack*)shmat(shmid, NULL, 0);
	if(shmaddr == (struct pack*)-1) {
		printf("shmaddr err \n");
		return 1;
	}

	shmaddr->op1=6;
	shmaddr->op2=9;
	for(int i=0, cnt=1; i<3; i++)
		for(int j=0; j<2; j++, cnt++)
			shmaddr->arr[i][j] = cnt; 

	// shmaddr->arr = { {1,2,3}, {4,5,6} };
	shmaddr->req = shmaddr->done = shmaddr->stop = 0;

	shmaddr->req = 1;
	printf("waiting for srv to finish \n");
	while(!shmaddr->done) {
		sleep(1);
	}
	printf("done \n");
	shmaddr->stop = 1;

	printf("res=%.2f \n", shmaddr->res);
	printf("arrsum=%.2f \n", shmaddr->arrsum);

	if(shmdt(shmaddr) == -1) {
		printf("shmdt err \n");
		return 1;
	}

	return 0;
}

int init_srv() {
	printf("server started \n");

	key_t key = ftok(".", 'a');
	if(key == -1) {
		printf("ftok err \n");
		return 1;
	}

	int shmid = shmget(key, sizeof(struct pack), 0666 | IPC_CREAT | IPC_EXCL);
	if(shmid == -1) {
		printf("shmget err: %s \n", strerror(errno));
		return 1;
	}

	struct pack* shmaddr = (struct pack*)shmat(shmid, NULL, 0);

	printf("waiting... \n");
	while(!shmaddr->stop) {
		if(shmaddr->req) {
			shmaddr->res = shmaddr->op1 + shmaddr->op2;

			shmaddr->arrsum = 0.f;
			for(int i=0; i<3; i++) 
				for(int j=0; j<2; j++)
					shmaddr->arrsum += shmaddr->arr[i][j];

			shmaddr->done = 1;
		}

		sleep(1);
	}
	printf("shutting down \n");

	if(shmdt(shmaddr) == -1) {
		printf("shmdt err \n");
		return 1;
	}

	if(shmctl(shmid, IPC_RMID, NULL) == -1) {
		printf("shmctl err \n");
		return 1;
	}

	return 0;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		printf("no args \n");
		return 1;
	}

	if(strcmp(argv[1], "-c") == 0)
		return init_cli();
	else if(strcmp(argv[1], "-s") == 0)
		return init_srv();
	else {
		printf("Invalid option! \n");
		return 1;
	}

	return 0;
}

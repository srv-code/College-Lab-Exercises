#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> //close()


struct pack {
	int matr[20][20], utmatr[20][20], ltmatr[20][20];
	int order, utmsum, ltmsum, sum;
};


int main(void) {
	struct sockaddr_in selfAddress, serverAddress;
	const int flags = 0;
	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	serverAddress.sin_family = AF_INET;	//IP family
	serverAddress.sin_port = htons(5300);	//serverPort
	serverAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5350);	//clientPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	struct pack work;
	printf("Order: ");
	scanf("%d", &work.order);
	printf("\nMatrix: \n");
	for(int i=0; i<work.order; i++) {
		printf("Row: %d \n", i+1);
		for(int j=0; j<work.order; j++) {
			printf("  Col %d: ", j+1);
			scanf("%d", &work.matr[i][j]);
		}
	}
	
	printf("\nMatrix:\n");
	for(int i=0; i<work.order; i++) {
		for(int j=0; j<work.order; j++) {
			printf("%d  ", work.matr[i][j]);
		}
		printf("\n");
	}


	unsigned int bufSize = sizeof(struct pack);
	unsigned int serverAddressSize = sizeof(serverAddress);
		
	sendto(socketfd, &work, bufSize, flags, (struct sockaddr*) &serverAddress, serverAddressSize);

	recvfrom(socketfd, &work, bufSize, flags, (struct sockaddr*) &serverAddress, &serverAddressSize);
	
	printf("\nResult:\n");
	
	printf("\nLTM:\n");
	for(int i=0; i<work.order; i++) {
		for(int j=0; j<work.order; j++) {
			printf("%d  ", work.ltmatr[i][j]);
		}
		printf("\n");
	}
	
	printf("\nUTM:\n");
	for(int i=0; i<work.order; i++) {
		for(int j=0; j<work.order; j++) {
			printf("%d  ", work.utmatr[i][j]);
		}
		printf("\n");
	}

	printf("\n");	
	printf("Sum of original matrix:           %d \n", work.sum);
	printf("Sum of upper triangular matrix:   %d \n", work.utmsum);
	printf("Sum of lower triangular matrix:   %d \n", work.ltmsum);
	
	close(socketfd);
	return 0;
}

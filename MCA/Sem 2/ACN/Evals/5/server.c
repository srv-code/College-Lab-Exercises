#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> //close()
#include <stdbool.h>


struct pack {
	int matr[20][20], utmatr[20][20], ltmatr[20][20];
	int order, utmsum, ltmsum, sum;
};

int main(void) {
	struct sockaddr_in selfAddress, clientAddress;
	const int flags = 0;
	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	unsigned int bufSize = sizeof(struct pack);
	unsigned int clientAddressSize = sizeof(clientAddress);
	
	struct pack work;
	
	while(1) {
		recvfrom(socketfd, &work, bufSize, flags, (struct sockaddr*) &clientAddress, &clientAddressSize);
		printf("[Packet received]\n");
		
			printf("Order: %d \n", work.order);
			printf("\nMatrix:\n");
			work.sum=0;
			for(int i=0; i<work.order; i++) {
				for(int j=0; j<work.order; j++) {
					printf("%d  ", work.matr[i][j]);
					work.sum += work.matr[i][j];
				}
				printf("\n");
			}
					
			printf("\nLTM:\n");
			work.ltmsum=0;
			for(int i=0; i<work.order; i++) {
				for(int j=0; j<work.order; j++) {
					if(j<=i) {
						work.ltmsum += work.matr[i][j];
						work.ltmatr[i][j] = work.matr[i][j];
					} else {
						work.ltmatr[i][j] = 0;
					}
					printf("%d  ", work.ltmatr[i][j]);					
				}
				printf("\n");
			}
			
			printf("\nUTM:\n");
			work.utmsum=0;
			for(int i=0; i<work.order; i++) {
				for(int j=0; j<work.order; j++) {
					if(j>=i) {
						work.utmsum += work.matr[i][j];
						work.utmatr[i][j] = work.matr[i][j];
					} else {
						work.utmatr[i][j] = 0;
					}
					printf("%d  ", work.utmatr[i][j]);
				}
				printf("\n");
			}
		
		
		sendto(socketfd, &work, bufSize, flags, (struct sockaddr*) &clientAddress, clientAddressSize);
		printf("\n[Packet sent]\n\n");
	}
	close(socketfd);
	return 0;
}

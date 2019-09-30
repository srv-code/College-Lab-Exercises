/* Write a C program for implementing chat server. */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>	//
#include <sys/socket.h>	//
#include <netinet/in.h>
#include <unistd.h> //close()

#define DEBUG 0


int main(void) {
	struct sockaddr_in selfAddress, clientAddress;

	const int flags = 0;

	int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	selfAddress.sin_family = AF_INET;	//IP family
	selfAddress.sin_port = htons(5300);	//serverPort
	selfAddress.sin_addr.s_addr = htonl(2130706433); //127.0.0.1

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));

	char buf[10];
	unsigned int bufSize = sizeof(buf);
	unsigned int clientAddressSize = sizeof(clientAddress);
	
	while(1) {
		bzero(buf, 10);
		recvfrom(socketfd, buf, bufSize, flags, (struct sockaddr*) &clientAddress, &clientAddressSize);
		printf("Received : %s\n", buf);

		size_t i;
		for(i=0; i<bufSize; i++) {
			if(buf[i] >= 65 && buf[i] <= 90)
				buf[i] = buf[i] + 32; //toSmall
			else if(buf[i] >= 97 && buf[i] <= 122)
				buf[i] = buf[i] - 32; //toCapital
		}
		sendto(socketfd, buf, bufSize, flags, (struct sockaddr*) &clientAddress, clientAddressSize);
		printf("Sent : %s\n\n", buf);

		/* DEBUG */
		if(DEBUG) {
			printf("  // buf='");
			for(int i1=0; buf[i1] != 0; i1++) {
				printf("%d:%c/%d;", i1, buf[i1], buf[i1]);
			}
			printf("', checklen=%ld, strcmp=%d \n", (long unsigned) strlen(buf)-1, strncmp(buf, "bye", strlen(buf)-1));
		}
		/* DEBUG */

		if(strncmp(buf, "bye", strlen(buf)-1) == 0)
			break;
	}
	close(socketfd);
	return 0;
}

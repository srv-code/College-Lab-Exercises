#include <stdio.h>
#include "globals.h"
 #include <sys/types.h>         
       #include <sys/socket.h>
       #include <netinet/in.h>

int main() {
	int flags = 0;
	struct sockaddr_in srv_addr, cli_addr;
	int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(5300);
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // htonl(2130706433);
//	srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // htonl(2130706433);
//	inet_aton("127.0.0.1", srv_addr.sin_addr.s_addr);

	cli_addr.sin_family = AF_INET;
	cli_addr.sin_port = htons(5350);
	cli_addr.sin_addr.s_addr = htonl(INADDR_ANY); // htonl(2130706433);
//	cli_addr.sin_addr.s_addr =  inet_addr("127.0.0.1"); // htonl(2130706433);
//	inet_aton("127.0.0.1", cli_addr.sin_addr.s_addr);

	bind(sockfd, (struct sockaddr*)&cli_addr, sizeof(struct sockaddr));
	connect(sockfd, (struct sockaddr*)&srv_addr, sizeof(struct sockaddr));
	
	struct msg pck;
	printf("start num:  ");
	scanf("%d", &pck.startnum);
	printf("end num:  ");
	scanf("%d", &pck.endnum);

	send(sockfd, (struct msg*)&pck, sizeof(struct msg), flags);
	recv(sockfd, (struct msg*)&pck, sizeof(struct msg), flags);

	for(int i=0; i<pck.arrlen; i++)
		printf("%d " , pck.resarr[i]);


	close(sockfd);
	
		
	return 0;
}

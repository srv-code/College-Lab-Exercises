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
//	srv_addr.sin_addr.s_addr =  
//	inet_aton("127.0.0.1", srv_addr.sin_addr.s_addr); // htonl(2130706433);

	bind(sockfd, (struct sockaddr*)&srv_addr, sizeof(struct sockaddr));
	listen(sockfd, 1);
	int s = sizeof(struct sockaddr);
	int cli_sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &s);

	struct msg pck;
	recv(cli_sockfd, &pck, sizeof(struct msg), flags);

	printf("start num: %d \n", pck.startnum);
	printf("end num: %d \n", pck.endnum);

	pck.arrlen=0;
	for(int s=pck.startnum; s<=pck.endnum; s++) {
		if(s%9==2 || s%9==3) {
			pck.resarr[pck.arrlen++] = s;
		}
	}

	send(cli_sockfd, &pck, sizeof(struct msg), flags);


	close(sockfd);
	
		
	return 0;
}

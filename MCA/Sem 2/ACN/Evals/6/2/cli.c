#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 


struct req {
    int id, qty, good;
    float tprice;
    char msg[50];
};

int main(void) {
	struct sockaddr_in selfAddress, serverAddress;
	const int flags = 0;
	int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(5300);	
	serverAddress.sin_addr.s_addr = htonl(2130706433); 

	selfAddress.sin_family = AF_INET;	
	selfAddress.sin_port = htons(5350);	
	selfAddress.sin_addr.s_addr = htonl(2130706433); 

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));
	connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(struct sockaddr));

    struct req r;
    printf("Item id: ");
	scanf("%d", &r.id);
	printf("Qty: ");
	scanf("%d", &r.qty);

	unsigned int bufSize = sizeof(struct req);
		
	send(socketfd, &r, bufSize, flags);

	recv(socketfd, &r, bufSize, flags);

    if(r.good)
        printf("%s%.2f \n", r.msg, r.tprice);
    else 
        printf("Message: %s \n", r.msg);

	close(socketfd);
	return 0;
}

/* UDP client in the internet domain */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

struct msgbuf {
    int operation;
    int operand1;
    int operand2;
};

/* Args: <hostname> <portno> */
int main(int argc, char *argv[])
{
    int sock, n;
    unsigned int length;
    struct sockaddr_in server, from;
    struct hostent *hp;
    struct msgbuf buf;

    if (argc != 3) 
        error("Usage: server port \n");
        
    sock= socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) 
        error("socket");

    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);

    if (hp==0) 
        error("Unknown host");

    bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    length=sizeof(struct sockaddr_in);

    printf("Select operation: \n");
    printf("  1 Add \n");
    printf("  2 Sub \n");
    printf("  3 Mul \n");
    printf("  4 Div \n");
    printf("Enter a choice:  ");
	scanf("%d", &(buf.operation));

	printf("Enter 2 numbers:  ");
	scanf("%d %d", &(buf.operand1), &(buf.operand2));
    
    n=sendto(sock, &buf, sizeof(struct msgbuf), 0, (const struct sockaddr *)&server, length);
    
    if (n < 0) 
        error("Sendto");

    int res;
    n = recvfrom(sock, &res, sizeof(int), 0, (struct sockaddr *)&from, &length);
    
    if (n < 0) 
        error("recvfrom");

    printf("Result:  %d \n", res);

    // write(1,"Got an ack: ",12);
    // write(1,buffer,n);
    close(sock);


    return 0;
}
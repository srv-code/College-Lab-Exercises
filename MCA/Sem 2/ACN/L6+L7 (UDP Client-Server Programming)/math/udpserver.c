/* Creates a datagram server. The port number is passed as an argument.
 This server runs forever */
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int calc(const int operation, const int a, const int b) {
    switch(operation) {
        case 1: 
            return a+b;

        case 2:
            return a-b;

        case 3:
            return a*b;

        case 4:
            return a/b;
        
        default: 
            write(1, "Invalid entry", 13);
            break;
	}
}

struct msgbuf {
    int operation;
    int operand1;
    int operand2;
};

/* Args: <port_no> */
int main(int argc, char *argv[]) {
    int sock, length, n;
    socklen_t fromlen;
    struct sockaddr_in server;
    struct sockaddr_in from;
    struct msgbuf buf;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sock=socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) 
        error("Opening socket");

    printf("[Server started] \n");

    length = sizeof(server);
    bzero(&server,length);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(atoi(argv[1]));

    if (bind(sock,(struct sockaddr *)&server,length) == -1)
        error("binding");

    fromlen = sizeof(struct sockaddr_in);

    while (1) {
        n = recvfrom(sock, &buf, sizeof(struct msgbuf), 0, (struct sockaddr *)&from, &fromlen);
        if (n == -1) 
            error("recvfrom");

        // write(1,"Received a datagram: ",21);
        // write(1,buf,n);
        int res = calc(buf.operation, buf.operand1, buf.operand2);
        n = sendto(sock, &res, sizeof(int), 0, (struct sockaddr *)&from, fromlen);
        if (n < 0) 
            error("sendto");
    }


    return 0;
}
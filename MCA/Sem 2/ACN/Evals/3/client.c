#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "globals.c"


int main() {
    printf("[Client started] \n");

	struct query_buf query;
	query.mtype = QUERY_MTYPE;

	printf("Enter inputs: \n");
    printf("  a:  ");
	scanf("%lf", &query.a);
    printf("  b:  ");
	scanf("%lf", &query.b);
    printf("  c:  ");
	scanf("%lf", &query.c);

//    printf("  // C: query.a=%f, query.b=%f, query.c=%f \n", query.a, query.b, query.c);

    key_t msqkey = ftok(".", 'a');
    if(msqkey == -1) {
        fprintf(stderr, "Client-side error: Cannot generate the message queue key (Details: %s) \n", strerror(errno));
		exit(1);
    }

	int msqid = msgget(msqkey, 0666);
	if(msqid == -1) {
		fprintf(stderr, "Client-side error: Cannot create a message queue (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	if(msgsnd(msqid, &query, sizeof(struct query_buf)-sizeof(long), IPC_NOWAIT) == -1) {
		fprintf(stderr, "Client-side error: Cannot send message to server (Details: %s) \n", strerror(errno));
		exit(1);
	}

	struct response_buf response;
	if(msgrcv(msqid, &response, sizeof(struct response_buf)-sizeof(long), RESP_MTYPE, 0) == -1) {
		fprintf(stderr, "Client-side error: Cannot receive message from server (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("Server: \n\tResult: \n\t\tRoot 1 = %.2f \n\t\tRoot 2 = %.2f \n", response.root1, response.root2);	

    printf("[Client closing...] \n");	
	
	return 0;
}

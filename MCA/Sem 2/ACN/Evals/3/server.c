#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "globals.c"
#include <math.h>


void calc_roots(const double a, const double b, const double c, double* root1, double* root2) {
    printf("  // a=%lf, b=%lf, c=%lf \n", a, b, c);
    *root1 = (-b + (sqrt((b*b)-(4.0*a*c))))/(2.0*a);
    *root2 = (-b + (sqrt((b*b)-(4.0*a*c))))/(2.0*a);
}

int main() {
    printf("[Server started] \n");
    key_t msqkey = ftok(".", 'a');
    if(msqkey == -1) {
        fprintf(stderr, "Server-side error: Cannot generate the message queue key (Details: %s) \n", strerror(errno));
		exit(1);
    }

	int msqid = msgget(msqkey, 0666 | IPC_CREAT | IPC_EXCL);
	if(msqid == -1) {
		fprintf(stderr, "Server-side error: Cannot fetch the message queue (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	struct query_buf query;
	if(msgrcv(msqid, &query, sizeof(struct query_buf)-sizeof(long), QUERY_MTYPE, 0) == -1) {
		fprintf(stderr, "Server-side error: Cannot receive query from client (Details: %s) \n", strerror(errno));
		exit(1);
	}

//    printf("  // C: query.a=%f, query.b=%f, query.c=%f \n", query.a, query.b, query.c);
	
	struct response_buf response;
	response.mtype = RESP_MTYPE;
    calc_roots(query.a, query.b, query.c, &response.root1, &response.root2);
	if(msgsnd(msqid, &response, sizeof(struct response_buf)-sizeof(long), IPC_NOWAIT) == -1) {
		fprintf(stderr, "Server-side error: Cannot send response to client (Details: %s) \n", strerror(errno));
		exit(1);
	}

	printf("Server: \n\tResult: \n\t\tRoot 1 = %.2f \n\t\tRoot 2 = %.2f \n", response.root1, response.root2);

	if(msgctl(msqid, IPC_RMID, 0) == -1) {
		fprintf(stderr, "Client-side error: Cannot remove msg queue (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
    printf("[Server closing...] \n");

	
	return 0;
}

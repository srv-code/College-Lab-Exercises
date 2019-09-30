/* 11) Write a client server program using message 
		queue to check for string palindrome as per 
		the input given by the client.
		
	>> Server module
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "globals.c"


int is_palindrome(const char str[], const int len) {
	for(int i=0, j=len-1; i<len/2; i++, j--) {
		if(str[i] != str[j])
			return 0;
	}
	return 1;
}

int main() {
    printf("[Server started] \n");

    // generate msgq key first
   	key_t msqkey = ftok(".", 'a');
	if(msqkey == -1) {
		fprintf(stderr, "Server-side error: Cannot generate message key (ftok: %s) \n", strerror(errno));
		exit(1);
	}

	// create msq exclusively
	int msqid = msgget(msqkey, 0666 | IPC_CREAT | IPC_EXCL);
	if(msqid == -1) {
		fprintf(stderr, "Server-side error: Cannot fetch the message queue (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	// receive query from server
	struct query_buf query;
	if(msgrcv(msqid, &query, sizeof(struct query_buf)-sizeof(long), QUERY_MTYPE, 0) == -1) {
		fprintf(stderr, "Server-side error: Cannot receive query from client (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	// respond to client
	struct response_buf response;
	response.mtype = RESP_MTYPE;
	response.is_palindrome = is_palindrome(query.string, query.slen);
	if(msgsnd(msqid, &response, sizeof(struct response_buf)-sizeof(long), IPC_NOWAIT) == -1) {
		fprintf(stderr, "Server-side error: Cannot send response to client (Details: %s) \n", strerror(errno));
		exit(1);
	}

	// destroy msgq now
	if(msgctl(msqid, IPC_RMID, 0) == -1) {
		fprintf(stderr, "Client-side error: Cannot remove msg queue (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
    printf("[Server closing...] \n");

	
	return 0;
}

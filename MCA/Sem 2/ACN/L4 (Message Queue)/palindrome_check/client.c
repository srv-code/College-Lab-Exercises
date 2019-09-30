/* 11) Write a client server program using message 
		queue to check for string palindrome as per 
		the input given by the client.
		
	>> Client module
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "globals.c"


int main() {
	struct query_buf query;
	query.mtype = QUERY_MTYPE;
	
	printf("Enter string:  ");
	scanf("%s", query.string);
	query.slen = strlen(query.string);

    // generate msgq key first
   	key_t msqkey = ftok(".", 'a');
	if(msqkey == -1) {
		fprintf(stderr, "Client-side error: Cannot generate message key (ftok: %s) \n", strerror(errno));
		exit(1);
	}
	
	// fetch msgq
	int msqid = msgget(msqkey, 0666);
	if(msqid == -1) {
		fprintf(stderr, "Client-side error: Cannot create a message queue (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	// send query to server
	if(msgsnd(msqid, &query, sizeof(struct query_buf)-sizeof(long), IPC_NOWAIT) == -1) {
		fprintf(stderr, "Client-side error: Cannot send message to server (Details: %s) \n", strerror(errno));
		exit(1);
	}

	// receive response from server
	struct response_buf response;
	if(msgrcv(msqid, &response, sizeof(struct response_buf)-sizeof(long), RESP_MTYPE, 0) == -1) {
		fprintf(stderr, "Client-side error: Cannot receive message from server (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("Result: String '%s' is palindrome: %s \n", query.string, response.is_palindrome ? "true" : "false");
	
	
	return 0;
}

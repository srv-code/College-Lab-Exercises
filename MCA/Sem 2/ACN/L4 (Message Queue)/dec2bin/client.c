/* 12) Write a client server program to convert 
		an array of decimal numbers to their 
		binary equivalent forms.
		
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
	
	int narr;
	printf("Enter array size:  ");
	scanf("%d", &narr);
	query.len = narr;
	
	printf("Enter %d decimal numbers: \n", narr);
	for(int i=0; i<narr; i++) {
		printf("  Number %d:  ", i+1);
		scanf("%d", &query.dec_arr[i]);
	}

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
	
	printf("\nResult: Equivalent binary conversions are: \n");
	for(int i=0; i<narr; i++) {
		printf("  [%d]  (%d)10 = (%d)2 \n", i+1, query.dec_arr[i], response.bin_arr[i]);
	}
		
	
	return 0;
}

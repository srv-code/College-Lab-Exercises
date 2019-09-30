/* 12) Write a client server program to convert 
		an array of decimal numbers to their 
		binary equivalent forms.
		
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


int dec2bin(int dec) {
	int bin = 0, exp=1;
	while(dec > 0) {
		bin = (exp*(dec%2)) + bin;
		dec /= 2;
		exp *= 10;
	}
	
	return bin;
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
	response.len = query.len;
	
	// fill contents to response
	for(int i=0, len=response.len; i<len; i++) {
		response.bin_arr[i] = dec2bin(query.dec_arr[i]);
	}
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

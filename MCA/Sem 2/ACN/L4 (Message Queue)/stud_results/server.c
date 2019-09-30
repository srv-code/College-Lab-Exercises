/* 13) Write a client server program to 
		accept an array of student data 
		and return the results to the 
		client. The student details should 
		be a structure data type containing 
		the following elements:
			Registration Number
			Student Name 
			Marks in 3 subjects
			
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
	struct msg_buf msg;
	if(msgrcv(msqid, &msg, sizeof(struct msg_buf)-sizeof(long), QUERY_MTYPE, 0) == -1) {
		fprintf(stderr, "Server-side error: Cannot receive query from client (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	// respond to client
	msg.mtype = RESP_MTYPE;
	
	// fill contents to response
	for(int i=0, len=msg.alen; i<len; i++) {
		msg.data[i].total_marks = msg.data[i].marks[0] + msg.data[i].marks[1] + msg.data[i].marks[2];
		msg.data[i].percentage = msg.data[i].total_marks/3;
		if(msg.data[i].percentage >= 90)
			msg.data[i].grade = 'O';
		else if(msg.data[i].percentage >= 80)
			msg.data[i].grade = 'A';
		else if(msg.data[i].percentage >= 70)
			msg.data[i].grade = 'B';
		else if(msg.data[i].percentage >= 60)
			msg.data[i].grade = 'C';
		else if(msg.data[i].percentage >= 50)
			msg.data[i].grade = 'D';
		else if(msg.data[i].percentage >= 40)
			msg.data[i].grade = 'E';
		else
			msg.data[i].grade = 'F';
	}
	
	if(msgsnd(msqid, &msg, sizeof(struct msg_buf)-sizeof(long), IPC_NOWAIT) == -1) {
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

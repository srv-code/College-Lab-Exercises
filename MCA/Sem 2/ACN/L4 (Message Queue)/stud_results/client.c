/* 13) Write a client server program to 
		accept an array of student data 
		and return the results to the 
		client. The student details should 
		be a structure data type containing 
		the following elements:
			Registration Number
			Student Name 
			Marks in 3 subjects
			
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
	struct msg_buf query;
	query.mtype = QUERY_MTYPE;
	
	printf("Enter number of students: ");
	int narr;
	scanf("%d", &narr);
	query.alen = narr;
	
	printf("Enter details of %d students: \n", narr);
	for(int i=0; i<narr; i++) {
		printf("  Student %d: \n", i+1);
		printf("      Registration number:  ");
		scanf("%d", &query.data[i].reg_no);
		printf("      Name:  ");
		scanf("%s", query.data[i].name);
		for(int j=0; j<3; j++) {
			printf("      Marks of Subject %d:  ", j+1);
			scanf("%f", &query.data[i].marks[j]);
		}
		printf("\n");
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
	if(msgsnd(msqid, &query, sizeof(struct msg_buf)-sizeof(long), IPC_NOWAIT) == -1) {
		fprintf(stderr, "Client-side error: Cannot send message to server (Details: %s) \n", strerror(errno));
		exit(1);
	}

	// receive response from server
	struct msg_buf response;
	if(msgrcv(msqid, &response, sizeof(struct msg_buf)-sizeof(long), RESP_MTYPE, 0) == -1) {
		fprintf(stderr, "Client-side error: Cannot receive message from server (Details: %s) \n", strerror(errno));
		exit(1);
	}
	
	printf("\nResults of %d students: \n", narr);
	for(int i=0; i<narr; i++) {
		printf("  Student %d: \n", i+1);
		printf("      Registration number:  %d \n", response.data[i].reg_no);
		printf("      Name:                 %s \n", response.data[i].name);
		printf("      Total marks:          %-3.2f \n", response.data[i].total_marks);
		printf("      Percentage:           %-3.2f \n", response.data[i].percentage);
		printf("      Grade:                %c \n", response.data[i].grade);
		printf("\n");
	}
		
	
	return 0;
}

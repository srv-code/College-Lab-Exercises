#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include "globals.c"

int main() {
	key_t key = ftok(".", 'a');
	int msqid = msgget(msqid, 0666);

	struct req_buf req; 
	req.mtype = REQ_MTYPE;

	req.len=0;	
	printf("Enter words: ");	
	char w[50];

	while(1) {
		scanf("%s ", w);
		printf("  // w=%s, strcmp=%d \n", w, strcmp(w, "--")==0);
/*
		if((strcmp(w, "--"))==0) {
			printf("  // break;");
			break;
		}
*/
		strcpy(req.words[req.len++], w);
		printf("  // copied: %s  \n", req.words[req.len++]);
		bzero(w, 50);
	}
	printf("  // outside");


	msgsnd(msqid, (struct req_buf*)&req, sizeof(struct req_buf), IPC_NOWAIT);
	
	struct resp_buf resp;
	resp.mtype = RESP_MTYPE;

	msgrcv(msqid, (struct resp_buf*)&req, sizeof(struct resp_buf), RESP_MTYPE, 0);

	printf("words \t vowels \t consonants \t specials");	
	for(int i=0; i<req.len; i++)
		printf("%s \t %d \t %d \t %d \n", req.words[i], resp.cvowels[i], resp.ccons[i], resp.csp[i]);

	return 0;
}

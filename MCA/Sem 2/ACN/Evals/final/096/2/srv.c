#include <stdio.h>
  #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
       #include <string.h>
#include "globals.c"


int main() {
	key_t key = ftok(".", 'a');
	int msqid = msgget(msqid, 0666|IPC_CREAT|IPC_EXCL);

	struct req_buf req; 
	req.mtype = REQ_MTYPE;
	msgrcv(msqid, (struct req_buf*)&req, sizeof(struct req_buf), REQ_MTYPE, 0);
	
	struct resp_buf resp;
	resp.mtype = RESP_MTYPE;
	
/*
	int inside=0;
	for(int i=0; i<req.len; i++) {
		if(isspace(req.str[i])) {
			inside=0;
			cwords++;
		} else if(isalpha(req.str[i])) {	
			switch(res.str[i]) {
				case 'a': case 'e': case 'i': case 'o': case 'u':
				case 'A': case 'E': case 'I': case 'O': case 'U':
					resp.cvowels++;
				default: 
					resp.ccons++;
			}
		} else {
			resp.str[i]
		}
	}
*/

	printf("string: ");		
	for(int i=0; i<req.len; i++) 
		printf("%s ", req.words[i]);
	printf("\n");	
	
	for(int i=0; i<req.len; i++) {
		for(int j=0; j<strlen(req.words[i]); j++) {
			if(isalpha(req.words[i][j])) {	
				switch(req.words[i][j]) {
					case 'a': case 'e': case 'i': case 'o': case 'u':
					case 'A': case 'E': case 'I': case 'O': case 'U':
						resp.cvowels[i]++;
					default: 
						resp.ccons[i]++;
				}
			} else {
				resp.csp[i]++;
			}
		}
	}

	msgsnd(msqid, (struct resp_buf*)&resp, sizeof(struct resp_buf), IPC_NOWAIT);
	msgctl(msqid, IPC_RMID, 0);
	
	return 0;
}

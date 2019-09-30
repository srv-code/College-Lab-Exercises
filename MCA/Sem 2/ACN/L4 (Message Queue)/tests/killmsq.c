#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


void kill_msq(const int msqid) {
    printf("Attempting to kill msq of id %d ... \n", msqid);
    if(msgctl(msqid, IPC_RMID, 0) == -1) 
        fprintf(stderr, "Result: Failed (%s) \n", strerror(errno));
    else 
        printf("Result: Succeeded \n");
}

int main(const int argc, char *argv[]) {
    kill_msq(atoi(argv[1]));


    return 0;
}

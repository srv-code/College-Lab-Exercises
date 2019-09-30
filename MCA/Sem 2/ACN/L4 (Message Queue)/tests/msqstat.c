#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


void show_msq_stats(const int msqid) {
    printf("Attempting to fetch stats of msqid %d ... \n", msqid);

    struct msqid_ds info;
    if(msgctl(msqid, IPC_STAT, &info) == -1) {
        fprintf(stderr, "Result: Failed (%s) \n", strerror(errno));
        exit(1);
    }

    printf("\n\tStats: \n");
    printf("msg_stime: %ld \n", info.msg_stime);
    printf("msg_qnum: %ld \n", info.msg_qnum);
    printf("msg_qbytes: %ld \n", info.msg_qbytes);
    printf("__msg_cbytes: %ld \n", info.__msg_cbytes);
    printf("msg_lspid: %d \n", info.msg_lspid);
    printf("msg_lrpid: %d \n", info.msg_lrpid);
}

int main(const int argc, char *argv[]) {
    show_msq_stats(atoi(argv[1]));


    return 0;
}

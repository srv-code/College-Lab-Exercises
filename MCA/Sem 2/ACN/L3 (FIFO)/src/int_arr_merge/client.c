/*  9) Using named pipes (FIFO’s), write a C program 
    to perform the operation of integer array merging 
    and the resultant array should be in sorted order.

    >> Client module: Writes the number of arrays to be
        sent and then writes all those arrays to the server 
        and finally receives the resultant array from the
        server
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


struct arr { // an individual array
    int len;
    int data[100];
};

struct msg_buf { // packetized array of arrays
    int count; // # of arrays passed
    struct arr arrs[20]; // array of arrays passed
};

int main() {
    const char* write_pipe_name = "npipe1";
    const char* read_pipe_name  = "npipe2";

    int write_pipe_fd = open(write_pipe_name, O_WRONLY, 0200);
    if(write_pipe_fd == -1) {
        fprintf(stderr, "Err: Cannot open pipe '%s' for writing! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    printf("[Client started] \n");

    struct msg_buf buf;
    printf("Enter count of arrays:  ");
    scanf("%d", &buf.count);

    // Input elements of individual arrays from user
    printf("Enter elements of %d arrays: \n", buf.count);
    for(int i=0; i<buf.count; i++) {
        printf("  Array %d: \n", i+1);
        printf("    Length:  ");
        scanf("%d", &buf.arrs[i].len);
        for(int j=0; j<buf.arrs[i].len; j++) {
            printf("      Element %2d:  ", j+1);
            scanf("%d", &buf.arrs[i].data[j]);
        }
    }
    
    // write the array of arrays to the server
    if(write(write_pipe_fd, &buf, sizeof(buf)) == -1) {
        fprintf(stderr, "Err: Cannot write to pipe '%s'! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    if(close(write_pipe_fd) == -1) {
        fprintf(stderr, "Err: Cannot close pipe %s' after writing! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    int read_pipe_fd = open(read_pipe_name, O_RDONLY, 0400);
    if(read_pipe_fd == -1) {
        fprintf(stderr, "Err: Cannot open pipe '%s' for reading! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;
    }

    struct arr farr;
    // read back the resultant array from the server
    if(read(read_pipe_fd, &farr, sizeof(farr)) == -1) {
        fprintf(stderr, "Err: Cannot read from pipe '%s'! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;        
    }
    
    if(close(read_pipe_fd) == -1) {
        fprintf(stderr, "Err: Cannot close pipe '%s' after reading! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;
    }

    printf("\nResultant merged and sorted array:  ");
    for(int i=0; i<farr.len; i++) {
        printf("%d  ", farr.data[i]);
    }
    printf("\n");


    return 0;
}
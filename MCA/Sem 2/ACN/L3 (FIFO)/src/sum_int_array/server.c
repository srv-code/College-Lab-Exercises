/*  8) Using named pipes (FIFO’s), write a C program
    to perform the summation of a given integer array.

    >> Server module: Reads the requested array from
        the client and writes back the summation of 
        that array
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


struct msg_buf {
    int len;
    int arr[20];
};

int main() {
    const char* read_pipe_name  = "npipe1";
    const char* write_pipe_name = "npipe2";

    int read_pipe_fd = open(read_pipe_name, O_RDONLY, 0400);
    if(read_pipe_fd == -1) {
        fprintf(stderr, "Err: Cannot open pipe '%s' for reading! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;
    }

    printf("[Server started] \n");

    struct msg_buf buf;
    // read the array from client
    if(read(read_pipe_fd, &buf, sizeof(buf)) == -1) {
        fprintf(stderr, "Err: Cannot read from pipe '%s'! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;        
    }

    if(close(read_pipe_fd) == -1) {
        fprintf(stderr, "Err: Cannot close pipe '%s' after reading! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;
    }

    // calculate sum of array
    int sum=0;
    for(int i=0; i<buf.len; i++) {
        sum += buf.arr[i];
    }

    int write_pipe_fd = open(write_pipe_name, O_WRONLY, 0200);
    if(write_pipe_fd == -1) {
        fprintf(stderr, "Err: Cannot open pipe '%s' for writing! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    // write back the summation to client
    if(write(write_pipe_fd, &sum, sizeof(sum)) == -1) {
        fprintf(stderr, "Err: Cannot write to pipe '%s'! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    if(close(write_pipe_fd) == -1) {
        fprintf(stderr, "Err: Cannot close pipe %s' after writing! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }
    
    printf("[Server closing...] \n");
    
    
    return 0;
}
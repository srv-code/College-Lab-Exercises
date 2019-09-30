/*  8) Using named pipes (FIFO’s), write a C program
    to perform the summation of a given integer array.

    >> Client module: Writes the requested array to
        the server and reads back the summation of 
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
    printf("Enter array size:  ");
    scanf("%d", &buf.len);

    for(int i=0; i<buf.len; i++) {
        printf("  Element %2d:  ", i+1);
        scanf("%d", &buf.arr[i]);
    }

    // write the array to the server
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

    int sum;
    // read back the summation from server
    if(read(read_pipe_fd, &sum, sizeof(int)) == -1) {
        fprintf(stderr, "Err: Cannot read from pipe '%s'! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;        
    }
    
    printf("Summation:  %d \n", sum);

    if(close(read_pipe_fd) == -1) {
        fprintf(stderr, "Err: Cannot close pipe '%s' after reading! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;
    }

    
    return 0;
}
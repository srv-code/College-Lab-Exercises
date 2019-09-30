/*  9) Using named pipes (FIFO’s), write a C program 
    to perform the operation of integer array merging 
    and the resultant array should be in sorted order.

    >> Server module: Reads the number of arrays to be
        received and then reads those arrays, merges 
        them and sorts the final array and writes it 
        back to the client
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

void merge_n_sort(const struct msg_buf *arrays, struct arr *farr) {
    int k=0;

    // first merge
    for(int i=0; i<arrays->count; i++) {
        for(int j=0; j<arrays->arrs[i].len; j++, k++) {
            farr->data[k] = arrays->arrs[i].data[j];
        }
    }
    farr->len=k; // sets length of rfesultant array    

    // now sort: applying insertion sort
    for(int i=1, j, key; i<farr->len; i++) {
        key = farr->data[i];
        for(j=i-1; j>=0; j--) {
            if(key < farr->data[j])
                farr->data[j+1] = farr->data[j];
            else 
                break;
        }
        farr->data[j+1] = key;
    }
}

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

    struct arr farr; // resultant array to be sent to the client
    merge_n_sort(&buf, &farr);

    int write_pipe_fd = open(write_pipe_name, O_WRONLY, 0200);
    if(write_pipe_fd == -1) {
        fprintf(stderr, "Err: Cannot open pipe '%s' for writing! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    // write back the summation to client
    if(write(write_pipe_fd, &farr, sizeof(farr)) == -1) {
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
/*  10) Write a program to validate the user name 
    and password given by the client and return the 
    result. 
    
    >> Client module: Writes the received username and 
        password combination to the server and reads 
        back the matching result
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


struct msg_buf {
    char    username[20], 
            password[20];
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
    printf("Enter username:  ");
    scanf("%s", buf.username);
    printf("Enter password:  ");
    scanf("%s", buf.password);

    // write the received credential to the server
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

    int result;
    // read back the match result from server
    if(read(read_pipe_fd, &result, sizeof(int)) == -1) {
        fprintf(stderr, "Err: Cannot read from pipe '%s'! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;        
    }

    printf("Result: Username and password match: %s \n", result ? "succeeded" : "failed");

    if(close(read_pipe_fd) == -1) {
        fprintf(stderr, "Err: Cannot close pipe '%s' after reading! (%s) \n", 
                read_pipe_name, strerror(errno));
        return 2;
    }


    return 0;
}
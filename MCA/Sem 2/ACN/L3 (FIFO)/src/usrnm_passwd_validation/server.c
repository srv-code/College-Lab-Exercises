/*  10) Write a program to validate the user name 
    and password given by the client and return the 
    result. 
    
    >> Server module: Reads the username and password 
        combination from client and check if thos two 
        matches with the combination held statically 
        in this server module and returns the 
        matching result
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


struct msg_buf {
    char    username[20], 
            password[20];
};

const char* USERNAME = "sourav";
const char* PASSWORD = "123$@";

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

    // read the credential sent by client
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

    int result = strcmp(USERNAME, buf.username)==0 && strcmp(PASSWORD, buf.password)==0;

    int write_pipe_fd = open(write_pipe_name, O_WRONLY, 0200);
    if(write_pipe_fd == -1) {
        fprintf(stderr, "Err: Cannot open pipe '%s' for writing! (%s) \n", 
                write_pipe_name, strerror(errno));
        return 2;
    }

    // write back the match result to client
    if(write(write_pipe_fd, &result, sizeof(int)) == -1)  {
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
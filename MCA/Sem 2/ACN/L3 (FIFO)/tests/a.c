#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


/* WON'T WORK */
/* test: int mkfifo (const char *pathname, mode_t mode); */
void test1(const int argc, const char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <pipe-name> \n", argv[0]);
        exit(1);
    }

    char pipe_name[10];
    strcpy(pipe_name, argv[1]);
    printf("pipe_name='%s' \n", pipe_name);

    // create, write, read - all here
    if(mkfifo(pipe_name, 0600) == -1) {    
        printf("Err: Cannot create FIFO pipe! (%s) \n", strerror(errno));
        exit(2);
    }

    printf("[Opening for writing only...] \n");
    int pipe_fd = open(pipe_name, O_WRONLY|O_CREAT|O_TRUNC, 0200);
    if(pipe_fd == -1) {
        printf("Err: Cannot open pipe! (%s) \n", strerror(errno));
        exit(2);
    }

    char* wbuf = "Hi this is Sourav!";
    int content_sz = strlen(wbuf);
    write(pipe_fd, wbuf, content_sz);
    if(close(pipe_fd) == -1) {
        printf("Err: Cannot close pipe! (%s) \n", strerror(errno));
    }

    printf("[Opening for reading only...] \n");
    pipe_fd = open(pipe_name, O_RDONLY, 0400);
    if(pipe_fd == -1) {
        printf("Err: Cannot open pipe! (%s) \n", strerror(errno));
        exit(2);
    }

    char rbuf[content_sz];
    read(pipe_fd, rbuf, content_sz);

    printf("Read content: '%s' \n", rbuf);

    if(close(pipe_fd) == -1) {
        printf("Err: Cannot close pipe! (%s) \n", strerror(errno));
    }
}

int main(const int argc, const char* argv[]) {
	test1(argc, argv);
	
	return 0;
}

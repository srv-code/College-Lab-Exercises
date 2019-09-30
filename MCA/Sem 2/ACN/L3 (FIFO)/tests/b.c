#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


void start_server(const char pipe_name[]) {
    // printf("  // Inside server(...) \n");
    printf("[Server started] \n");
	int fd_pipe = open(pipe_name, O_RDONLY, 0400);
	if(fd_pipe == -1) {
		printf("Err: Cannot open pipe (%s)! \n", pipe_name);
		exit(2);
	}

	ssize_t nread;
	const int MAX_BUF_SIZE = 4096; // 4k buffer
	char buf[MAX_BUF_SIZE];
	for(int i=0; i<5 && (nread=read(fd_pipe, buf, MAX_BUF_SIZE)) > 0; i++) {
		printf("S: itr=%2d, nread=%3ld, MSG='%s' \n", i, nread, buf);
        bzero(buf, nread); // clears previous buffer content
	}
	
	if(close(fd_pipe) == -1) {
		printf("Err: Cannot close pipe (%s)! \n", pipe_name);
	}

    printf("[Server closing...] \n");
}

void start_client(const char pipe_name[]) {
    // printf("  // Inside client(...) \n");
	int fd_pipe = open(pipe_name, O_WRONLY, 0200);
	if(fd_pipe == -1) {
		printf("Err: Cannot open pipe (%s)! \n", pipe_name);
		exit(2);
	}

    printf("[Client started] \n");

	ssize_t nwrite;
	const int MAX_BUF_SIZE = 4096; // 4k buffer
	char buf[MAX_BUF_SIZE];
	for(int i=0; i<5; i++) {
        printf("Enter msg %d:  ", i);
		scanf("%s", buf);
        // printf("  // msg='%s' \n", buf);
        write(fd_pipe, buf, strlen(buf));
	}
	
	if(close(fd_pipe) == -1) {
		printf("Err: Cannot close pipe (%s)! \n", pipe_name);
	}
}

/* For already created FIFO pipe via mknod/mkfifo command */
void test1(const int argc, const char* argv[]) {
	if(argc != 3) {
		printf("Usage: %s -s|-c <pipe_name> \n", argv[0]);
		exit(1);
	}

	if(strcmp(argv[1], "-s")==0) {
        // printf("  // test1(...) exhausted. \n");
		start_server(argv[2]);
	} else if(strcmp(argv[1], "-c")==0) {
        // printf("  // test1(...) exhausted. \n");
		start_client(argv[2]);
	} else {
		printf("Err: Invalid option! \n");
		exit(1);
	}
}

/* Will first created FIFO pipe if not already exists */
void test2(const int argc, const char* argv[]) {
	if(argc != 3) {
		printf("Usage: %s -s|-c <pipe_name> \n", argv[0]);
		exit(1);
	}

    // /* int mkfifo (const char *pathname, mode_t mode); */
    // if(strcmp(argv[1], "-s") == 0) { // create only if server is invoked
    //     if(mkfifo(argv[2], 0644) == -1) {
    //         printf("Err: Cannot create FIFO pipe using mkfifo(...)! (%s) \n", strerror(errno));
    //         exit(2);
    //     }
    // }

    /* int mknod(const char *pathname, mode_t mode, dev_t dev); 
       mode:
            S_IFREG -> won't work, creates a regular/plain file
            S_IFIFO -> only this will work, FIFO pipe 
            S_IFSOCK -> Cannot be opened
       dev: only works for S_IFCHR and S_IFBLK
    */
    if(strcmp(argv[1], "-s") == 0) { // create only if server is invoked
        if(mknod(argv[2], 0600 | S_IFIFO, 0) == -1) {
            printf("Err: Cannot create FIFO pipe using mknod(...)! (%s) \n", strerror(errno));
            exit(2);
        }
    }

    // printf("  // test2(...) exhausted. \n");
    test1(argc, argv); // call the older routine
}

int main(const int argc, const char* argv[]) {
	// test1(argc, argv);
	test2(argc, argv);
	
	
	return 0;
}

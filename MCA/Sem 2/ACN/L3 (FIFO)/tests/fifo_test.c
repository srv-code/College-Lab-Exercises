#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(const int argc, const char* argv[]) {
	if(argc != 2) {
		printf("Usage: <mode> <pipename> \n");
		return 1;
	}

	enum MODE {
		NONE=-1, SERVER, CLIENT
	};

	const enum MODE mode = strcmp(argv[0], "./server")==0 ? SERVER : (strcmp(argv[0], "./client")==0 ? CLIENT : NONE);
	// printf("  // mode=%d, SERVER=%d, CLIENT=%d, NONE=%d \n", mode, SERVER, CLIENT, NONE);

	if(mode == NONE) {
		printf("Mode should be server or client only! \n");
		return 1;
	}

	const char* pipename = argv[1];
	printf("Using fifo pipe='%s'... \n", pipename);

	if(mode == SERVER) { // acts as server: reads		
		int fd = open(pipename, O_RDONLY, 0400);
		printf("fd=%d \n", fd);
		char buf[10];
		printf("read=%ld \n", read(fd, buf, sizeof(buf)));		
		printf("close=%d \n", close(fd));
	} else { // acts as client: writes
		int fd = open(pipename, O_WRONLY, 0200);
		printf("fd=%d \n", fd);
		char *buf = "text";
		printf("write=(%ld/%ld) \n", write(fd, buf, sizeof(buf)), sizeof(buf));		
		printf("close=%d \n", close(fd));
	}

	return 0;
}
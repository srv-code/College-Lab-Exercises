#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


int main(const int argc, const char* argv[]) {
	int fd = creat(argv[1], 0644);
	printf("fd=%d \n", fd);
	printf("close=%d \n", close(fd));
	
	return 0;
}
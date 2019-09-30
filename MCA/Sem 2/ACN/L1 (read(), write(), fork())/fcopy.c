/* File copy operation using 
 * file related system calls */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(const int argc, const char* argv[]) {
	if(argc != 3) {
		fprintf(stderr, "Usage: %s <src_file> <dst_file> \n", argv[0]);
		return 1;
	}
	
	printf("Src file: %s \n", argv[1]);
	printf("Dst file: %s \n", argv[2]);
	
	int src_fd = open(argv[1], O_RDONLY, 0400);
	if(src_fd == -1) {
		fprintf(stderr, "Err: Cannot open src file for reading (%s) \n", strerror(errno));
		return 1;
	}

	int dst_fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0600);
	if(dst_fd == -1) {
		fprintf(stderr, "Err: Cannot open dst file for writing (%s) \n", strerror(errno));
		return 1;
	}

	printf("Performing copy operation... \n");
	
	ssize_t nread, tread=0, twrite=0;
	const int MAX_BUF_SIZE = 4096; // 4K buffer
	char buf[MAX_BUF_SIZE];
	
	while((nread = read(src_fd, buf, MAX_BUF_SIZE)) > 0) {
		tread += nread;
		twrite += write(dst_fd, buf, nread);
	}

	printf("Total bytes read from src file:  %ld \n", tread);
	printf("Total bytes written to dst file: %ld \n", twrite);

	int successful=1;
	if(close(src_fd) == -1) {
		fprintf(stderr, "Err: Failed to close src file (%s) \n", strerror(errno));
		successful=0;
	}
	
	if(close(dst_fd) == -1) {
		fprintf(stderr, "Err: Failed to close dst file (%s) \n", strerror(errno));
		successful=0;
	}

	if(successful)
		printf("Operation was successful \n");


	return 0;
}

/* Program to merge two or more files
 * in a child process and display the 
 * result of merging using fork() system call. */

#include <stdio.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>


int main(const int argc, const char* argv[]) {
	if(argc < 3) { // min requirement: <prg_name> <src_file> <dst_file>
		fprintf(stderr, "Usage: %s <src_file_1>[ <src_file_2>...] <dst_file> \n", argv[0]);
		return 1;
	}
	
	pid_t status = fork();
	
	if(status == -1) {
		fprintf(stderr, "Err: Unable to fork! \n");
		return 2;
	}
	
	if(status == 0) { // child proc to handle the file I/O operations
		printf("Opening file '%s' as dst file... \n", argv[argc-1]);
		int dst_fd = open(argv[argc-1], O_RDWR | O_TRUNC | O_CREAT, 600); // open dst file, last param
		if(dst_fd == -1) {
			fprintf(stderr, "Err: Failed to open dst file '%s' (%s) \n", argv[argc-1], strerror(errno));
			return 1; // no point in continuing operation
		}
		
		const int MAX_BUF_SIZE = 4096; // 4K buffer
		char buf[MAX_BUF_SIZE];
		ssize_t nread;
		
		for(int i=1; i<argc-1; i++) { // all argv[1 to argc-2] params are treated as src files
			printf("\nMerging from source file '%s'... \n", argv[i]);
			int src_fd = open(argv[i], O_RDONLY, 400);
			if(src_fd == -1) {
				fprintf(stderr, "Err: Cannot open src file '%s' for reading (%s) \n", argv[i], strerror(errno));
				return 1;
			}
			
			ssize_t nwrite=0;
			while((nread = read(src_fd, buf, MAX_BUF_SIZE)) > 0) {
				nwrite += write(dst_fd, buf, nread);
			}
			printf("  Total bytes written: %ld \n", nwrite);
			
			if(close(src_fd) == -1)
				fprintf(stderr, "Err: Failed to close src file '%s' (%s) \n", argv[i], strerror(errno));
		}
		
		// show final contents written to dst file
		if(lseek(dst_fd, 0, SEEK_SET) == -1) { // position file pointer to beg of file
			fprintf(stderr, "Err: Cannot set pointer in dst file '%s' for reading (%s) \n", argv[argc-1], strerror(errno));			
		} else {
			ssize_t tread=0;
			printf("\n\nMerged file ('%s') contents: \n", argv[argc-1]);
			while((nread = read(dst_fd, buf, MAX_BUF_SIZE)) > 0) {
				tread += nread;
				write(1, buf, nread); // writes to the stdout file
			}
			printf("\n-----------------------------\nTotal bytes read: %ld \n", tread);
		}
		
		if(close(dst_fd) == -1)
			fprintf(stderr, "Err: Failed to close dst file '%s' (%s) \n", argv[argc-1], strerror(errno));
	} else {
		wait(NULL); // parent proc waits for child to finish
	}

	return 0;
}

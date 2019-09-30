#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>


void to_upper(char buf[], const int BUF_SIZE) {
	for(int i=0; i<BUF_SIZE; i++) {
		if(buf[i] >= 'a' && buf[i] <= 'z')
			buf[i] = 'A'+(buf[i]-'a');
	}
}

int main() {
	const int BUF_SIZE = 30;
	char* buf = "Hi! This are the file contents";
	pid_t status = fork();
	
	if(status == -1) {
		printf("Err: Cannot fork! \n");
		return 1;
	}
	
	if(status == 0) { // Child proc
		int a1_fd = open("a1.txt", O_RDONLY, 0400);
		if(a1_fd == -1) {
			printf("Err: Cannot open a1.txt! \n");
			return 1;
		}
		
		char rbuf[BUF_SIZE];
		read(a1_fd, rbuf, BUF_SIZE);
		
		if(close(a1_fd) == -1) {
			printf("Err: Cannot close a1.txt! \n");
		}
		
		to_upper(rbuf, BUF_SIZE);
		
		int a2_fd = open("a2.txt", O_RDWR | O_CREAT | O_TRUNC, 0700);
		if(a2_fd == -1) {
			printf("Err: Cannot open a2.txt! \n");
			return 1;
		}
		
		write(a2_fd, rbuf, BUF_SIZE);
		char nbuf[BUF_SIZE];
		lseek(a2_fd, 0, SEEK_SET);
		read(a2_fd, nbuf, BUF_SIZE);
		printf("Contents of a2.txt: \n");
		write(1, nbuf, BUF_SIZE); // write to stdout
		printf("\n");
		
		if(close(a2_fd) == -1) {
			printf("Err: Cannot close a2.txt! \n");
		}
	} else { // Parent proc
		int a1_fd = open("a1.txt", O_RDWR | O_CREAT | O_TRUNC, 0700);
		if(a1_fd == -1) {
			printf("Err: Cannot open a1.txt! \n");
			return 1;
		}
		
		char rbuf[BUF_SIZE];
		write(a1_fd, buf, BUF_SIZE);
		lseek(a1_fd, 0, SEEK_SET);
		
		char wbuf[BUF_SIZE];
		printf("Contents of a1.txt: \n");
		read(a1_fd, wbuf, BUF_SIZE);
		write(1, wbuf, BUF_SIZE); // write to stdout
		printf("\n");
		if(close(a1_fd) == -1) {
			printf("Err: Cannot close a1.txt! \n");			
		}
		
		wait(NULL); // wait for child proc to finish
	}
	
	
	return 0;
}

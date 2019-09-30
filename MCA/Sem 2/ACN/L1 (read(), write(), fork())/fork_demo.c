/* Demonstrating the fork() system call usage. */

#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t status = fork();
	
	if(status == -1) {
		fprintf(stderr, "Err: Fork failed. \n");
		return 1;
	}
	
	if(status == 0) {
		printf("Child process:  pid=%d \n", getpid());
	} else {
		printf("Parent process: pid=%d \n", getpid());
	}


	return 0;
}

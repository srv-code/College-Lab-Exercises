/*
	Write a Client Server Program to input a string
	or number on the client and check whether they 
	are palindromes and return the result from the 
	server to the client.
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int is_palindrome(const char str[], const int len) {
	for(int i=0, j=len-1; i<len/2; i++, j--) {
		if(str[i] != str[j])
			return 0;
	}
	return 1;
}

int main(const int argc, const char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Usage: %s <string_to_test> \n", argv[0]);
		return 1;
	}

	int fd[2];
	if(pipe(fd) == -1) {
		fprintf(stderr, "Err: Unable to create pipes. \n");
		return 2;
	}	
	
	int status = fork();
	
	if(status == -1) {
		fprintf(stderr, "Err: Unable to fork! \n");
		return 3;
	}
	
	if(status == 0) {
		close(fd[0]); // close read end
		int res = is_palindrome(argv[1], strlen(argv[1]));
		write(fd[1], &res, sizeof(int));
		close(fd[1]); // close write end
	} else {
		close(fd[1]); // close write end
		int res;
		read(fd[0], &res, sizeof(int));
		close(fd[0]); // close read end
		printf("Result: String '%s' is palindrome: %s \n", argv[1], res ? "True" : "False" );
	}

	return 0;
}

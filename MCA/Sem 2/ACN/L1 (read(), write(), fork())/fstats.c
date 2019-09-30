/* Program to read a file and use the child process
 * to count the number of words, vowels and
 * consonants within the file and display the result. */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>


int main(const int argc, const char* argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Usage: %s <src_file> \n", argv[0]);
		return 1;
	}
	
	printf("Src file: %s \n", argv[1]);

	int successful=1;
	int src_fd = open(argv[1], O_RDONLY, 0400);
	if(src_fd == -1) {
		fprintf(stderr, "Err: Cannot open src file for reading. \n");
		return 1;
	}

	ssize_t nread;
	const int BUF_MAX_SIZE = 4096; // 4K buffer
	char buf[BUF_MAX_SIZE];
	
	printf("Reading src file... \n");
	nread = read(src_fd, buf, BUF_MAX_SIZE); // assuming src file size <= 4K
	printf("Read %ld bytes from src file. \n", nread);
	
	if(close(src_fd) == -1) {
		fprintf(stderr, "Err: Failed to close src file. \n");
		successful=0;
	}
	
	pid_t status = fork();
	
	if(status == -1) {
		fprintf(stderr, "Err: Fork failed. \n");
		return 2;
	}
	
	if(status == 0) {
		// Child process: perform counting operation	
		printf("Child process: Performing counting operation... \n");
		int outside_word=1;
		long nvowels=0L, ncons=0L, nwords=0L;
		char c;
		for(int i=0; i<nread; i++) {
			c = buf[i];
			if(isalpha(c)) {
				switch(c) {
					case 'a': case 'A':
					case 'e': case 'E':
					case 'i': case 'I':
					case 'o': case 'O':
					case 'u': case 'U':
						nvowels++; break;
					default:
						ncons++;
				}
			}
			
			if(isspace(c)) {
				outside_word = 1;
			} else {
				if(outside_word) {
					nwords++;
					outside_word = 0;
				}
			}
		}
	
		// Print statistics
		printf("Word count:      %ld \n", nwords);
		printf("Vowel count:     %ld \n", nvowels);
		printf("Consonant count: %ld \n", ncons);
		return 0;
	} else {
		wait(NULL);
	}

	if(successful)
		printf("All operations were successful \n");


	return 0;
}

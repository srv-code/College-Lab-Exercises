#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	long n;
	int fds[2], status;
	do {
		status = pipe(fds);
		if(status != -1) 
			n++;
	} while(status != -1);

	printf("Pipe creation limit: %ld \n", n);

	return 0;
}

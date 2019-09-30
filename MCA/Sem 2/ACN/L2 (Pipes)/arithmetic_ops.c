/*
	Write a C program to perform menu based 
	arithmetic operations using pipes.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int close_all(const int fd1, const int fd2, const int fd3) {
	int status = 0;
	status += close(fd1);
	status += close(fd2);
	status += close(fd3);
	return status;
}

int main() {
	int fd1[2], fd2[2];
	
	if(pipe(fd1) == -1 || pipe(fd2) == -1) {
		fprintf(stderr, "Err: Unable to create pipes! \n");
		return 1;
	}
	
	int status = fork();
	
	if(status == -1) {
		fprintf(stderr, "Err: Unable to fork! \n");
		return 2;
	}
	
	if(status == 0) {
		// child proc: acts as server
		close(fd1[1]);
		int pack[3], res;
		
		read(fd1[0], pack, sizeof(int)*3);
		close(fd1[0]);
		
		switch(pack[0]) {
			case 1: res = pack[1]+pack[2]; break;
			case 2: res = pack[1]-pack[2]; break;
			case 3: res = pack[1]*pack[2]; break;
			case 4: res = pack[1]/pack[2]; break;
		}
		
		close(fd2[0]);
		write(fd2[1], &res, sizeof(int));
		close(fd2[1]); 
	} else {
		close(fd1[0]);
		// parent proc: acts as client
		int pack[3], res; // packet to send to server: [0]=operator, [1]=operand 1, [2]=operand 2
		printf("Select an operation to perform: \n");
		printf("  1  Addition \n");
		printf("  2  Subtraction \n");
		printf("  3  Multiplication \n");
		printf("  4  Division \n");
		printf("Choice:  ");
		scanf("%d", &pack[0]);
		
		if(pack[0] < 1 || pack[0] > 4) {
			printf("Invalid choice! \n");
			// Do clean up before exitingclose_all
			close_all(fd1[1], fd2[0], fd2[1]);
			return 3;
		}
		
		printf("Enter two operands:  ");
		scanf("%d %d", &pack[1], &pack[2]);
		
		if(pack[0] == 4 && pack[2] == 0) {
			printf("Cannot divide by zero! \n");
			// Do clean up before exiting
			close_all(fd1[1], fd2[0], fd2[1]);
			return 3;
		}
		
		write(fd1[1], pack, sizeof(int)*3);
		close(fd1[1]);
		
		close(fd2[1]);
		read(fd2[0], &res, sizeof(int));
		printf("Result:  %d \n", res);
		close(fd2[0]);
	}
	
	
	return 0;
}
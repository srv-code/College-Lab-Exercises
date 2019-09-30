#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


void test1(char *fname) {
	char *wbuf = "hello";
	int fd = open(fname, O_RDWR|O_CREAT, 0777);
	ssize_t nwrite = write(fd, wbuf, strlen(wbuf));
	printf("nwrite=%ld, wbuf='%s' \n", (long)nwrite, wbuf);
/*
	printf("closing fd=%d! \n", fd);
	close(fd); // file closed!!! 
	printf("fd=%d closed! \n", fd);
*/
	char rbuf[10];
	lseek(fd, 0, SEEK_SET);
	ssize_t nread = read(fd, rbuf, 10);
	printf("nread=%ld, rbuf='%s' \n", (long)nread, rbuf);
}

void test3() {
	int fds[2];
	int pipe_status = pipe(fds);
	printf("pipe status=%d \n", pipe_status);
	close(fds[1]);
	printf("write: %ld \n", (long)write(fds[1], "hi", 2));
	printf("DONE \n");
}

void test2() {
	int fds[2];
	int status = pipe(fds);
	printf("pipe status=%d \n", status);
	if(fork()==0) {
		printf("C: read end=%d, write end=%d \n", fds[0], fds[1]);
		close(fds[0]); // close read end
		printf("C: closed read end \n");
		printf("C: writing.. \n");
		char wbuf[] = "hello from child";
		printf("C: write=%ld \n", (long)write(fds[1], wbuf, strlen(wbuf)));
		printf("C: wbuf='%s', DONE \n", wbuf);
		close(fds[1]); // close write end
		printf("C: closed write end \n");
	} else {
		printf("P: read end=%d, write end=%d \n", fds[0], fds[1]);
		close(fds[1]); // close write end
		printf("P: closed write end \n");
		printf("P: reading.. \n");
		char rbuf[20];
		printf("P: read=%ld \n", (long)read(fds[0], rbuf, 20));
		printf("P: rbuf='%s', DONE \n", rbuf);
		close(fds[0]); // close read end
		printf("P: closed read end \n");
	}
}

typedef struct {
	int id;
	char name[20];
} node;

/*	VM sir: Try with passing (structure) via pipe(or FIFO)
	to another process */
void test4() {
	int fd[2];
	if(pipe(fd) == -1) {
		printf("Err: cannot pipe! \n");
		exit(1);
	}

	printf("fd[0]=%d, fd[1]=%d \n", fd[0], fd[1]);

	pid_t status = fork();
	if(status == -1) {
		printf("Err: cannot fork! \n");
		exit(1);
	}

	if(status == 0) {
		// child proc
		if(close(fd[1]) == -1) 
			printf("S: Err: failed to close fd[1] \n");
		node node1;
		ssize_t nread = read(fd[0], &node1, sizeof(node));
		printf("S: read %ld bytes \n", nread); // receiving struct type
		
		if(nread > 0)
			printf("S: received node: {%d,%s} \n", node1.id, node1.name);
		if(close(fd[0]) == -1) 
			printf("S: Err: failed to close fd[0] \n");
	} else {
		// parent proc 
		if(close(fd[0]) == -1) 
			printf("C: Err: failed to close fd[0] \n");
		node node1;
		node1.id = 12;
		strcpy(node1.name, "sourav");
		printf("C: written %ld bytes \n", 
			write(fd[1], &node1, sizeof(node1)) ); // sending struct type
		if(close(fd[1]) == -1)
			printf("C: Err: failed to close fd[1] \n");

		wait(NULL);
	}
}

void test5() {
	node* n = malloc(sizeof(node));
	// printf("%ld \n", sizeof(n->id));
	n->id = 12;
	strcpy(n->name, "sourav");
	printf("{%d,%s} \n", n->id, n->name);
}

/*	VM sir: Try with passing (array of structure)
	via pipe(or FIFO) to another process */
void test6() {
	int fd[2];
	if(pipe(fd) == -1) {
		printf("Err: cannot pipe! \n");
		exit(1);
	}

	printf("fd[0]=%d, fd[1]=%d \n", fd[0], fd[1]);

	pid_t status = fork();
	if(status == -1) {
		printf("Err: cannot fork! \n");
		exit(1);
	}

	const int nelements = 3;

	if(status == 0) {
		// child proc
		if(close(fd[1]) == -1) 
			printf("S: Err: failed to close fd[1] \n");
		node nodes[nelements];
		ssize_t nread = read(fd[0], nodes, sizeof(node)*nelements);
		printf("S: read %ld bytes \n", nread); // receiving struct array type
		
		if(nread > 0) {
			for(int i=0; i<nelements; i++)
				printf("S: received:  [%2d]  {%d,%s} \n", i+1, nodes[i].id, nodes[i].name);
		}
		
		if(close(fd[0]) == -1) 
			printf("S: Err: failed to close fd[0] \n");
	} else {
		// parent proc 
		if(close(fd[0]) == -1) 
			printf("C: Err: failed to close fd[0] \n");
		node nodes[nelements];
		for(int i=0; i<nelements; i++) {
			nodes[i].id=(i+1)*50;
			strcpy(nodes[i].name, "name");
		}
		
		printf("C: written %ld bytes \n", 
			write(fd[1], nodes, sizeof(node)*nelements) ); // sending struct array type
		if(close(fd[1]) == -1)
			printf("C: Err: failed to close fd[1] \n");

		wait(NULL);
	}
}

/* 	Try with passing (using pointer to structure) via 
	pipe(or FIFO) to another process . */
void test7() {
	int fd[2];
	if(pipe(fd) == -1) {
		printf("Err: cannot pipe! \n");
		exit(1);
	}

	printf("fd[0]=%d, fd[1]=%d \n", fd[0], fd[1]);

	pid_t status = fork();
	if(status == -1) {
		printf("Err: cannot fork! \n");
		exit(1);
	}

	if(status == 0) {
		// child proc
		if(close(fd[1]) == -1) 
			printf("S: Err: failed to close fd[1] \n");
		// node* pnode;
		node node1;
		ssize_t nread = read(fd[0], &node1, sizeof(node));
		printf("S: read %ld bytes \n", nread); // receiving pointer to struct type
		
		printf("S: received: {%d,%s} \n", node1.id, node1.name);
		
		if(close(fd[0]) == -1) 
			printf("S: Err: failed to close fd[0] \n");
	} else {
		// parent proc 
		if(close(fd[0]) == -1) 
			printf("C: Err: failed to close fd[0] \n");
		
		node node1;
		node1.id = 45; strcpy(node1.name, "people");
		node* pnode = &node1;
		// printf("  // pnode=%ld, &pnode=%ld \n", pnode, &pnode);
		printf("  // C: sending: {%d,%s} \n", pnode->id, pnode->name); // test
		printf("C: written %ld bytes \n", 
			write(fd[1], pnode, sizeof(node)) ); // sending pointer to struct type
		if(close(fd[1]) == -1)
			printf("C: Err: failed to close fd[1] \n");

		wait(NULL);
	}
}

int main(int argc, char *argv[]) {
	// test1(argv[1]);
	// test2();
	// test4();
	// test5();
	// test6();
	test7();
	
	return 0;
}

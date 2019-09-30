#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


void test_ftok(const char* fname) {
	printf("fname=%s \n", fname);
	printf("ftok=%d \n", ftok(fname, 'x'));
}

int main(const int argc, const char *argv[]) {
	test_ftok(argv[1]);

	return 0;
}

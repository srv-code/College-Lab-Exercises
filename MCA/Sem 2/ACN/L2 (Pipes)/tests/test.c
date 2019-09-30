#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	char *buf = "hello\n";
	ssize_t nwrite = write(1, buf, strlen(buf));
	printf("nwrite = %ld \n", (long)nwrite);

	return 0;
}

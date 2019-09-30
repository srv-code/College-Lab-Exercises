#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int dec2bin(int dec) {
	int bin = 0, exp=1;
	while(dec > 0) {
		bin = (exp*(dec%2)) + bin;
		// printf("  // dec=%d, exp=%d, dec%2=%d, bin=%d \n", dec, exp, dec%2, bin);
		dec /= 2;
		exp *= 10;
	}
	
	return bin;
}

int test_dec2bin() {
    int dec;
	printf("Dec:  ");
	scanf("%d", &dec);
	printf("Bin: %d \n", dec2bin(dec));
}

int main(const int argc, char *argv[]) {
	test_dec2bin();
	
	
	return 0;
}

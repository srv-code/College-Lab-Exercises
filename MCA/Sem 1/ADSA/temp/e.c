#include <stdio.h>

void fn(char* exp, const int len) 
{
	int new_len = len + 2, new_exp[new_len];	
	int i;
	
	new_exp[0] = '(';
	new_exp[new_len-1] = ')';
	
	// copy from original expression array
	for(i=0; i<len; i++)
		new_exp[i+1] = exp[i];
		
	printf("Printing new_exp... \n");
	for(i=0; i<new_len; i++)
		printf("new_exp[%d]='%c' (%d) \n", i, new_exp[i], new_exp[i]);
}

char* fn1() 
{
	char x[] = "sourav";
	printf("returning %s from fn1()... \n", x);
	return x;
}

int main() 
{
	// fn("a*b", 3);
	char *s; s = fn1();
	int i;
	// for(i=0; *(s+i) != 0; i++) 
	// 	printf("%c", *(s+i));
	// printf("\n");
	
	return 0;
}
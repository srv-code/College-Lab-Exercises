#include <stdio.h>
#include <stdlib.h>
#include "../../../../stack.c"

#define MAX_EXP_LEN 20

const int DEBUG_ENABLED = 0; // DEBUG

int main() 
{
	char exp[MAX_EXP_LEN];
	
	system("clear");
	
	printf("Exp:  ");
	scanf("%s", &exp);
	
	printf("Result:  %d \n", eval_exp(exp));
	
	
	return 0;
}

int eval_exp(const char exp[])
{
	int i, len, x, a, b;
	char c;
	Stack s;
	
	len = strlen(exp) - 1;
	if(init_stack(&s, len) == -1) {
		printf("Error: Cannot init stack! \n");
		exit(-1);
	}
	
	// postfix -- start from right
	for(i=len; i>=0; i--) {
		c = exp[i];
		switch(c) {
			case '+':
			case '*':		
			case '-':		
			case '/':
					
					err_if_stack_empty(s, DEBUG_ENABLED);
					a = pop_from_stack(&s);
					err_if_stack_empty(s, DEBUG_ENABLED);
					b = pop_from_stack(&s);
					
					if(c == '+') x = a + b;
					if(c == '*') x = a * b;
					if(c == '-') x = a - b;
					if(c == '/') x = a / b;
					
					push_to_stack(&s, x);
					
					if(DEBUG_ENABLED) {
						printf("After %c: \n", c); // DEBUG
						display_stack(s); // DEBUG
					}
					
					break;
					
			default: // should have to be a num
				x = c - '0';
				if(x < 0 || x > 9) {
					// check if a valid num
					printf("Error: Not a valid num '%c' (ASCII=%d) (index=%d) \n", c, c, i);
					printf("Exp:  %s \n", exp);
					printf("      ");
					for(a=0; a<i; a++)
						printf(" ");
					printf("^ \n");
					exit(-1);
				}
				
				push_to_stack(&s, x);
				
				if(DEBUG_ENABLED) {
					printf("After num '%d', pushed to stack: \n", x); // DEBUG
					display_stack(s); // DEBUG
				}
		}
	}
	
	x = pop_from_stack(&s); // answer
	
	err_if_stack_not_empty(s, DEBUG_ENABLED);
	
	return x;
}
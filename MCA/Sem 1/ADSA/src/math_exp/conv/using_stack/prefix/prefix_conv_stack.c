#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../../../stack.c"

#define MAX_EXP_LEN 20

const int DEBUG_ENABLED = 0;


int main() 
{
	char infix_exp[MAX_EXP_LEN], prefix_exp[MAX_EXP_LEN];
	
	printf("Infix expression:    ");
	scanf("%s", &infix_exp);
	if(strlen(infix_exp) > MAX_EXP_LEN) {
		printf("Error: Input string length is greater than max size! \n");
		exit(1);
	} 

	if(DEBUG_ENABLED)
		printf("\nInfix expression:    %s \n", infix_exp);
	
	conv_exp(infix_exp, prefix_exp);
	printf("Prefix expression:  %s \n", prefix_exp);

	return 0;
}

void conv_exp(const char iexp[MAX_EXP_LEN], char pexp[MAX_EXP_LEN])
{
	int i, j;
	int iexp_len = strlen(iexp);
	char tiexp[iexp_len+2]; // temp infix array with ( at the start
	tiexp[0] = '(';
	tiexp[1] = 0;
	Stack s;

	if(init_stack(&s, iexp_len+1) == -1) {
		printf("Error: Stack size is greater than max size! \n");
		exit(2);
	}

	push_to_stack(&s, ')');

	strcat(tiexp, iexp);

	// calculate size of pexp
	for(i=0, j=0; i<iexp_len; i++)
		if(iexp[i] != '(' && iexp[i] != ')')
			j++;
	pexp[j] = 0; // set end of string

	char c, x;
	for(--j; i>=0; i--) {
		c = tiexp[i];

		if(DEBUG_ENABLED)
			printf("  [consider: i=%d, j=%d, c=%c] \n", i, j, c);

		if(is_operator(c)) {
			// operator found
			/*
				If an operator op is encountered, then
					a)	Repeatedly pop from the stack and add to the left of P each
						operator (on the top of the stack) which has higher precedence
						than op.
					b) 	Add op to the stack.
			*/
			if(DEBUG_ENABLED)
				printf("    [op found=%c] \n", c); 

			while(is_operator(x=peek_in_stack(s)) && is_higher_op(x, c)) {
				if(DEBUG_ENABLED) 
					printf("    [next is higher op=%c, adding to pexp...] \n", x);

				pexp[j--] = pop_from_stack(&s);
			}
			push_to_stack(&s, c);
		} else if(c == '(') {
			// left parenthesis found
			/* 
				If a left parenthesis is encountered, then
					a)	Repeatedly pop from the stack and add to the left of P each
						operator (on the top of the stack) until a right parenthesis 
						is encountered.
					b)	Remove the right parenthesis. [Do not add the right
						parenthesis to P]
			*/
			if(DEBUG_ENABLED)
				printf("    [( found] \n");

			while(peek_in_stack(s) != ')') {
				if(DEBUG_ENABLED) 
					printf("    [adding %c to pexp] \n", peek_in_stack(s));

				pexp[j--] = pop_from_stack(&s);
			}
			pop_from_stack(&s); // discard the left parenthesis which caused the while loop to abort
		} else if(c == ')') {
			// right parenthesis found
			/* 
				If a right parenthesis is encountered, 
				push it onto the stack.
			*/
			if(DEBUG_ENABLED)
				printf("    [) found, adding to stack] \n");

			push_to_stack(&s, c);
		} else {
			// treat as an operand
			/*
				If an operand is encountered, add it to the left of P.
			*/
			if(DEBUG_ENABLED) 
				printf("    [adding operand (%c) to pexp] \n", c);

			pexp[j--] = c;
		}
	}

	if(DEBUG_ENABLED)
		if(j != -1) 
			printf("  [Error: j is not -1] \n");
}

int is_operator(const int c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*
	checks if operator a is higher in precedence than the operator b
*/
int is_higher_op(const int a, const int b)
{
	if(a == '/' || a == '*')
		if(b == '+' || b == '-')
			return 1;
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../../../stack.c"

#define MAX_EXP_LEN 20

const int DEBUG_ENABLED = 0;


int main() 
{
	char infix_exp[MAX_EXP_LEN], postfix_exp[MAX_EXP_LEN];
	
	printf("Infix expression:    ");
	scanf("%s", &infix_exp);
	if(strlen(infix_exp) > MAX_EXP_LEN) {
		printf("Error: Input string length is greater than max size! \n");
		exit(1);
	} 

	if(DEBUG_ENABLED)
		printf("\nInfix expression:    %s \n", infix_exp);
	
	conv_exp(infix_exp, postfix_exp);
	printf("Postfix expression:  %s \n", postfix_exp);

	return 0;
}

void conv_exp(const char iexp[MAX_EXP_LEN], char pexp[MAX_EXP_LEN])
{
	int i, j;
	int iexp_len = strlen(iexp);
	char tiexp[iexp_len+2]; // temp infix array with ) in end	
	Stack s;

	if(init_stack(&s, iexp_len+1) == -1) {
		printf("Error: Stack size is greater than max size! \n");
		exit(2);
	}

	push_to_stack(&s, '(');

	strcpy(tiexp, iexp);
	strcat(tiexp, ")");

	// printf("checking for 0 in tiexp... \n");
	// for(i=0; tiexp[i] != 0; i++);
	// printf("0 found at %d in tiexp \n", i);
	
	char c, x;
	for(i=0, j=0; tiexp[i] != 0; i++) {
		c = tiexp[i];

		if(DEBUG_ENABLED)
			printf("  [consider: i=%d, j=%d, c=%c] \n", i, j, c);

		if(is_operator(c)) {
			// operator found
			/*
				If an operator op is encountered, then
				a) Repeatedly pop from the stack and add to the right of P each
				operator (on the top of the stack) which has the same
				precedence as or higher precedence than op.
				b) Add op to the stack.
			*/
			if(DEBUG_ENABLED)
				printf("    [op found=%c] \n", c); 

			while(is_operator(x=peek_in_stack(s)) && op_precedence(c, x)) {
				if(DEBUG_ENABLED) 
					printf("    [next is also op=%c, adding to pexp?=%d] \n", x, op_precedence(c, x));

				pexp[j++] = pop_from_stack(&s);
			}
			push_to_stack(&s, c);
		} else if(c == ')') {
			// right parenthesis found
			/* 
				If a right parenthesis is encountered, then
				a) Repeatedly pop from the stack and add to the right of P each
				operator (on the top of the stack) until a left parenthesis is
				encountered.
				b) Remove the left parenthesis. [Do not add the left parenthesis
				to P]
			*/
			if(DEBUG_ENABLED)
				printf("    [) found] \n");

			while(peek_in_stack(s) != '(') {
				if(DEBUG_ENABLED) 
					printf("    [adding %c to pexp] \n", peek_in_stack(s));

				pexp[j++] = pop_from_stack(&s);
			}
			pop_from_stack(&s); // discard the left parenthesis which caused the while loop to abort
		} else if(c == '(') {
			// left parenthesis found
			/* 
				If a left parenthesis is encountered, 
				push it on to the stack.
			*/
			if(DEBUG_ENABLED)
				printf("    [( found, adding to stack] \n");

			push_to_stack(&s, c);
		} else {
			// treat as an operand
			/*
				If an operand is encountered, add it to the right of P.
			*/
			if(DEBUG_ENABLED) 
				printf("    [adding operand (%c) to pexp] \n", c);

			pexp[j++] = c;
		}
	}
	pexp[j] = 0;
}

int is_operator(const int c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*
	returns 0 if current operator is of higher precedence than the next operator
	returns 1 if current operator is of lower or equal precedence than the next operator
*/
int op_precedence(const int c, const int x) 
{
	if(c == '/' || c == '*')
		if(x == '+' || x == '-')
			return 0;
	return 1;
}
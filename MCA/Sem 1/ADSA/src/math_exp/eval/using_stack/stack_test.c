#include <stdio.h>
#include "../../../stack.c"

int main() 
{
	system("clear");

	stack s;
	init_stack(&s, 3);
	
	printf("stack full?: %d \n", is_stack_full(s));
	printf("stack empty?: %d \n", is_stack_empty(s));
	
	printf("Inserting 10... \n");
	push_to_stack(&s, 10);
	
	printf("Inserting 20... \n");
	push_to_stack(&s, 20);
	
	display_stack(s);
	
	printf("stack full?: %d \n", is_stack_full(s));
	printf("stack empty?: %d \n", is_stack_empty(s));
	
	printf("Inserting 30... \n");
	push_to_stack(&s, 30);
	
	display_stack(s);
	
	printf("stack full?: %d \n", is_stack_full(s));
	printf("stack empty?: %d \n", is_stack_empty(s));
	
	printf("pop: %d \n", pop_from_stack(&s)); 
	
	printf("stack full?: %d \n", is_stack_full(s));
	printf("stack empty?: %d \n", is_stack_empty(s));
	
	printf("pop: %d \n", pop_from_stack(&s)); 
	printf("pop: %d \n", pop_from_stack(&s)); 
	
	printf("stack full?: %d \n", is_stack_full(s));
	printf("stack empty?: %d \n", is_stack_empty(s));
	
	return 0;
}
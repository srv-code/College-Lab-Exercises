#include <stdio.h>

const int MAX_STACK_SIZE = 5;

int is_stack_empty(const int top)
{ 
	return top == -1;
}

int is_stack_full(const int top)
{
	return top == MAX_STACK_SIZE - 1;
}

void push_to_stack(int stack[MAX_STACK_SIZE], int* top, const int e)
{
	stack[++(*top)] = e;
}

int pop_from_stack(const int stack[MAX_STACK_SIZE], int* top)
{
	return stack[(*top)--];
}

void display_stack(const int stack[MAX_STACK_SIZE], const int top)
{
	int i;
	printf("\nIndex \t\t Element \n");
	for(i=top; i>=0; i--)
		printf("%5d \t\t %7d \n", i, stack[i]);
}

int main() 
{
	int stack[MAX_STACK_SIZE], top = -1, continue_input = 1, inp, element;
	
	system("clear");
	
	while(continue_input)
	{
		printf("\n\nEnter choice: \n");
		printf("  1  Push \n");
		printf("  2  Pop \n");
		printf("  3  Display \n");
		printf("  4  Exit \n");
		printf("Choice?  ");
		scanf("%d", &inp);
		
		switch(inp) 
		{
			case 1 : // push
				if( is_stack_full(top) )
					printf("Stack is full!");
				else
				{
					printf("Element?  ");
					scanf("%d", &element);
					push_to_stack(stack, &top, element);
					printf("Element %d is pushed to stack", element);
				}				
				break;
				
			case 2: // pop
				if( is_stack_empty(top) )
					printf("Stack is empty!");
				else 
					printf("Element popped: %d \n", pop_from_stack(stack, &top));
				break;
				
			case 3: // display
				if( is_stack_empty(top) )
					printf("Stack is empty!");
				else 
					display_stack(stack, top);
				break;
				
			case 4: // exit
				continue_input = 0;
				break;
				
			default:
				printf("  [Inspecting...] \n");
				printf("  [top=%d] \n", top);
				//printf("Invalid choice! Try again.");
		}
	}
	
	return 0;
}
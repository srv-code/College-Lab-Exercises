#include <stdio.h>

const int MAX_QUEUE_SIZE = 5;

int is_queue_full(const int rear)
{
	return rear == MAX_QUEUE_SIZE - 1;
}

int is_queue_empty(const int front, const int rear)
{
	return front == rear;
}

void push_to_queue(int queue[MAX_QUEUE_SIZE], int* rear, const int e)
{
	queue[++(*rear)] = e;
}

int pop_from_queue(int queue[MAX_QUEUE_SIZE], int* front)
{
	return queue[++(*front)];
}

void display_queue(const int queue[MAX_QUEUE_SIZE], const int front, const int rear)
{
	int i;
	printf("\nIndex \t\t Element \n");
	for(i=front+1; i<=rear; i++)
		printf("%5d \t\t %7d \n", i, queue[i]);
}

int main() 
{
	int queue[MAX_QUEUE_SIZE], front = -1, rear = -1, continue_input = 1, inp, element;
	
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
				if( is_queue_full(rear) )
					printf("Queue is full!");
				else
				{
					printf("Element?  ");
					scanf("%d", &element);
					push_to_queue(queue, &rear, element);
					printf("Element %d is pushed", element);
				}				
				break;
				
			case 2: // pop
				if( is_queue_empty(front, rear) )
					printf("Queue is empty!");
				else 
					printf("Element popped: %d", pop_from_queue(queue, &front));
				break;
				
			case 3: // display
				if( is_queue_empty(front, rear) )
					printf("Queue is empty!");
				else 
					display_queue(queue, front, rear);
				break;
				
			case 4: // exit
				continue_input = 0;
				break;
				
			default:
				printf("Invalid choice! Try again.");
		}
	}
	
	return 0;
}
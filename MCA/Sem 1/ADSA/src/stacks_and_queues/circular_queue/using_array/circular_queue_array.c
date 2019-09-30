#include <stdio.h>

#define MAX_QUEUE_SIZE 3

const int DEBUG_MODE_ENABLED = 0; // DEBUG

typedef struct
{
	int		arr[MAX_QUEUE_SIZE],
			front, rear;
	char	last_op; // 'o' = pop & 'u' = push
} circular_queue_array;

void init_cqueue(circular_queue_array* cq)
{
	if(DEBUG_MODE_ENABLED) // DEBUG
		printf("  [init cqueue] \n");

    (*cq).front = 0;
    (*cq).rear = 0;
    (*cq).last_op = 'o';
}

void inspect(const circular_queue_array cq) // DEBUG
{
    printf("  [cqueue: front=%d, rear=%d, full?=%d, empty?=%d] \n", // DEBUG
				cq.front, cq.rear, is_cqueue_full(cq), is_cqueue_empty(cq)); //DEBUG
}

int is_cqueue_full(const circular_queue_array cq)
{
	return (cq.rear == cq.front && cq.last_op == 'u');
}

int is_cqueue_empty(const circular_queue_array cq)
{
    return (cq.front == cq.rear && cq.last_op == 'o');
}

void push_to_cqueue(circular_queue_array* cq, const int e)
{
    int r = (*cq).rear;
	(*cq).last_op = 'u';
	(*cq).rear = (r+1) % MAX_QUEUE_SIZE;
	(*cq).arr[r] = e;
		
	if(DEBUG_MODE_ENABLED)
		printf("  [pushing to cqueue: element=%d, new rear=%d, front=%d] \n", e, r, (*cq).front);
}

int pop_from_cqueue(circular_queue_array* cq)
{
	int f, e;
	(*cq).last_op = 'o';
	f = (*cq).front;
    e = (*cq).arr[f];
	
	(*cq).front = (f+1) % MAX_QUEUE_SIZE;

    if(DEBUG_MODE_ENABLED)
		printf("  [popping from cqueue: element=%d, rear=%d, new front=%d] \n",
			e, (*cq).rear, f);
	
	return e;
}

void display_cqueue(const circular_queue_array cq)
{
    int i, s, lim;
			
	if(DEBUG_MODE_ENABLED)
		inspect(cq); // DEBUG
		
    printf("\n  Index \t\t\t Elements \n");
    printf  ("  ----- \t\t\t -------- \n");
	
    for(i = s = cq.front, lim = cq.rear, lim = (s >= lim) ? MAX_QUEUE_SIZE+lim : lim; 
    	s < lim; 
    	s++, i=(i+1)%MAX_QUEUE_SIZE)
	{
		if(DEBUG_MODE_ENABLED)
			printf("        [Loop: i=%d, s=%d, lim=%d] \n", i, s, lim);
		printf("  %5d \t\t\t %8d \n", i, cq.arr[i]);
	}
}

int main()
{
    circular_queue_array cqueue;
    int continue_input = 1, inp, element;

    system("clear");

    if(DEBUG_MODE_ENABLED) // DEBUG
		printf("\n    [**IN DEBUG MODE**] \n"); // DEBUG

    init_cqueue(&cqueue);

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
				if( is_cqueue_full(cqueue) )
                printf("Circular queue is full!");
                else
                {
					printf("Element?  ");
                    scanf("%d", &element);
                    push_to_cqueue(&cqueue, element);
                    printf("Element %d is pushed", element);
                }
                
				break;

            case 2: // pop
				if( is_cqueue_empty(cqueue) )
					printf("Circular queue is empty!");
                else
					printf("Element popped: %d", pop_from_cqueue(&cqueue));
             
				break;

            case 3: // display
				if( is_cqueue_empty(cqueue) )
					printf("Circular queue is empty!");
                else
					display_cqueue(cqueue);
                
				break;

            case 4: // exit
				continue_input = 0;                
				break;

            default:
				if(DEBUG_MODE_ENABLED) // DEBUG
					inspect(cqueue); // DEBUG
                else  // DEBUG
					printf("Invalid choice! Try again.");
        }
    }

    return 0;
}
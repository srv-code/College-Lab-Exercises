#define MAX_STACK_SIZE 20

typedef struct 
{
	int top;
	int arr[MAX_STACK_SIZE];
	int len;
} Stack;

int init_stack(Stack* s, const int len)
{
	if(len > MAX_STACK_SIZE)
		return -1;
		
	(*s).len = len;
	(*s).top = -1;
	
	return 0;
}

int is_stack_empty(const Stack s)
{ 
	return s.top == -1;
}

int is_stack_full(const Stack s)
{
	return s.top == s.len - 1;
}

void push_to_stack(Stack* s, const int e)
{
	(*s).arr[++(*s).top] = e;
}

int peek_in_stack(Stack s)
{
	return s.arr[s.top];
}

int pop_from_stack(Stack* s)
{
	return (*s).arr[(*s).top--];
}

void display_stack(const Stack s)
{
	int i;
	printf("Index \t\t Element \n");
	for(i=s.top; i>=0; i--)
		printf("%5d \t\t %7d \n", i, s.arr[i]);
}

void err_if_stack_not_empty(const Stack s, const int show_debug_info) { err_stack_contents(s, 0, show_debug_info); }

void err_if_stack_empty(const Stack s, const int show_debug_info)  { err_stack_contents(s, 1, show_debug_info); }

void err_stack_contents(const Stack s, const int empty_reqd, const int show_debug_info)
{
	if(is_stack_empty(s) == empty_reqd) {
		printf("Invalid exp! [Reason: %s elements in stack] \n", empty_reqd ? "Lesser" : "More");
		if(!empty_reqd)
			if(show_debug_info) {
				printf("Stack contents: \n");
				display_stack(s);
			}
		exit(-1);
	}
}
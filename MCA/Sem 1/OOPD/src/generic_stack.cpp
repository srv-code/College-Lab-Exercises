#include <iostream>
#include <cstdlib> // for personal system compatibility 

using namespace std;


template<class T>
class Stack
{
	public: 
		static const int MAX_SIZE = 5;

	private:
		int top;
		T arr[MAX_SIZE];
		// T* arr = new T[MAX_SIZE];

	public:
		Stack() { top = -1; }

		void push(const T);
		T pop();
		bool is_full();
		bool is_empty();
};

// template <class T>
// static const int Stack<T>::MAX_SIZE = 5;

template<class T>
void Stack<T>::push(const T element)
{
	// No limit checking here, relies on external check with bool Stack::is_full()
	arr[++top] = element;
}

template<class T>
T Stack<T>::pop() 
{
	// No limit checking here, relies on external check with bool Stack::is_empty()
	return arr[top--];
}

template <class T>
bool Stack<T>::is_full() 
{
	return top == MAX_SIZE-1;
}

template <class T>
bool Stack<T>::is_empty() 
{
	return top == -1;
}


template <class T>
void test_stack(const int type) 
{
	cout << "\nEnter ";
	switch(type) {
		case 1: cout << "integer"; break;
		case 2: cout << "float"; break;
		case 3: cout << "character"; break;
		case 4: cout << "long"; break;
		case 5: cout << "string"; break;
	}
	cout << " type values:" << endl;
	
	Stack<T> stack;

	int choice; bool continue_input = true;
	while(continue_input) {
		cout 	<< "Choose operation: \n"
				<< "  1  Push \n"
				<< "  2  Pop \n"
				<< "  3  Exit \n"
				<< "Choice:  ";
		cin >> choice;

		switch(choice) {
			case 1: // Push
				if(stack.is_full()) {
					cerr << "Error: Stack is full!" << endl;
				} else {
					T e;
					cout << "Element:  "; 
					cin >> e;
					stack.push(e);
					cout << "Element " << e << " pushed." << endl;
				}
				break;

			case 2: // Pop
				if(stack.is_empty()) {
					cerr << "Error: Stack is empty!" << endl;
				} else {
					cout << "Element:  " << stack.pop() << endl;
				}
				break;

			case 3:
				continue_input = false;
				break;

			default: 
				cerr << "Error: Invalid choice provided! Try again." << endl;
		}
		cout << endl;
	}
}

int main() 
{
	system("clear");

	int choice;
	bool continue_input = true;

	while(continue_input) {
		cout 	<< "Select data type of stack: \n"
				<< "  1  Integer \n"
				<< "  2  Floating point \n"
				<< "  3  Charcter \n"
				<< "  4  Long \n"
				<< "  5  String \n"
				<< "Choice:  ";
		cin >> choice;
		continue_input = false;
		switch(choice) {
			case 1: // Call for int type tester
					test_stack<int>(choice);
					break;

			case 2: // Call for float type tester
					test_stack<float>(choice);
					break;

			case 3: // Call for char type tester
					test_stack<char>(choice);
					break;

			case 4: // Call for long type tester
					test_stack<long>(choice);
					break;
					
			case 5: // Call for string type tester
					test_stack<string>(choice);
					break;
					
			default: 
				cerr << "Error: Invalid choice! Try again.\n" << endl;
				continue_input = true;
		}
	}
	

	return 0;
}
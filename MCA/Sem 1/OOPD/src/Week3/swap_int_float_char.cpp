// Author name: Sourav Dey
// Date of creation: 13-Aug-2018
// Week number: 3
// Program name: To swap two integers, floats, and characters using function-overloading

#include <iostream>

#include <cstdlib> // Remove

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main() 
{
	int continue_input = 1, choice;
	int int_a, int_b;
	float float_a, float_b;
	char char_a, char_b;
	
	system("clear");
	
	while(continue_input) 
	{
		cout << "Enter choice of data type for swapping: \n";
		cout << "  1  Integer \n";
		cout << "  2  Floating point \n";
		cout << "  3  Character \n";
		cout << "Choice: ";
		cin >> choice;
		
		if(continue_input = (choice < 1 || choice > 3) )
			cerr << "Error: Invalid entry! Please try again. \n";		
	}
	
	cout << "Enter two inputs of choosen type: \n";
	
	switch(choice)
	{
		case 1: // For ints
			cin >> int_a;
			cin >> int_b;
			cout << "Before swapping: " << int_a << ", " << int_b << endl;
			swap(&int_a, &int_b);
			cout << "After swapping: " << int_a << ", " << int_b << endl;

			break;
			
		case 2: // For floats
			cin >> float_a;
			cin >> float_b;
			cout << "Before swapping: " << float_a << ", " << float_b << endl;
			swap(&float_a, &float_b);
			cout << "After swapping: " << float_a << ", " << float_b << endl;
			break;
			
		case 3: // For chars
			cin >> char_a;
			cin >> char_b;
			cout << "Before swapping: " << char_a << ", " << char_b << endl;
			swap(&char_a, &char_b);
			cout << "After swapping: " << char_a << ", " << char_b << endl;
			break;
			
		default:
			cerr << "Internal Error: Invalid choice: " << choice << endl;
			exit(-1);
	}

	return 0;
}
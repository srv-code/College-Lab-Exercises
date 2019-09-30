//Code 7.0
#include <iostream>

using namespace std;

void func1(int a) // pass by value
{
	a = 2;
	cout << "address = " << &a << endl;
	cout << "value = " << a << endl ;
}

void func2(int & a) //pass by reference
{
	a = 3;
	cout << "address = " << &a << endl;
	cout << "value = " << a << endl ;
}

void func3(int *a) //pass by address or pointer
{
	*a = 4;
	cout << "address = " << a << endl;
	cout << "value = " << *a << endl ;
}

int main()
{
	int b=1;
	
	cout << "before func1, value of b = " << b << endl;
	func1(b);
	cout << "after func1, value of b = " << b << endl << endl;
	
	cout << "before func2, value of b = " << b << endl;
	func2(b);
	cout << "after func2, value of b = " << b << endl << endl;
	
	cout << "before func3, value of b = " << b << endl;
	func3(&b);
	cout << "after func3, value of b = " << b << endl << endl;

	return 0;
}
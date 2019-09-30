// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: Exchange 2 values without using temp variable

#include <iostream>

using namespace std;

int main() 
{
	int a, b;
	
	// system("clear");
	
	cout << "Enter value of a: ";
	cin >> a;
	
	cout << "Enter value of b: ";
	cin >> b;
	
	cout << "Before exchange: a=" << a << ", b=" << b << endl;
	
	a = a + b;
	b = a - b;
	a = a - b;

	cout << "After exchange:  a=" << a << ", b=" << b << endl;

	
	return 0;
}
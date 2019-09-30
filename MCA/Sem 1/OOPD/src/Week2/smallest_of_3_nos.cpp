// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: Find the smallest of 3 numbers

#include <iostream>

using namespace std;

int main() 
{
	int a, b, c;

	// system("clear");

	cout << "Enter value of a: ";
	cin >> a;

	cout << "Enter value of b: ";
	cin >> b;

	cout << "Enter value of c: ";
	cin >> c;


	cout << "Smallest of 3 numbers: " << ((a < b) ? (a < c ? a : c) : (b < c ? b : c)) << endl;
	
	
	return 0;
}
// Author name: Sourav Dey
// Date of creation: 13-Aug-2018
// Week number: 3
// Program name: To find the cube of a number

#include <iostream>

#include <cstdlib> // Remove 

using namespace std;

inline int get_cube(const int n)
{ return n*n*n; }

int main() 
{
	int num;
	system("clear");
	
	cout << "Enter a number: ";
	cin >> num;
	
	cout << "Result: " << get_cube(num) << endl;
	
	return 0;
}
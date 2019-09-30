// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: Print a triangular pattern using *

#include <iostream>

using namespace std;

int main() 
{
	int line_count, i, j;
	
	// system("clear");
	
	cout << "Enter no of lines of patterns: ";
	cin >> line_count;
	
	// using nested for loops
	cout << "Printing using nested for loops:" << endl;
	for(i = 1; i <= line_count; i++)
	{
		for(j = 0; j < i; j++)
			cout << "*  ";
		cout << endl;
	}
	
	cout << endl;
	
	// using nested while loops
	i = 0;
	cout << "Printing using nested while loops:" << endl;	
	while(i++ < line_count)
	{
		j = 0;
		while(j++ < i)
			cout << "*  ";
		cout << endl;
	}
	
	
	return 0;
}
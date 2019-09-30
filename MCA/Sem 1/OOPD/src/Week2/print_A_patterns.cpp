// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: Print an upside down triangular pattern using A

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
	for(i = line_count; i > 0; i--)
	{
		for(j=0; j < i; j++)
			cout << "A  ";
		cout << endl;
	}
	
	cout << endl;
	
	// using nested while loops
	i = line_count;
	cout << "Printing using nested while loops:" << endl;	
	while(i-- > 0)
	{
		j = 0;
		while(j++ <= i)
			cout << "A  ";
		cout << endl;
	}
	
	
	return 0;
}
// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: Generate the first n terms of the Fibonacci sequence

#include <iostream>

using namespace std;

int main() 
{
	int term;
	
	// system("clear");
	
	cout << "Enter term count: ";
	cin >> term;
	
	cout << "First " << term << " terms of Fibonacci sequence: " << endl;

	int prev_no = 0, curr_no = 1;

	// Manual printing of first two nos
	cout << prev_no << "  " << curr_no << "  ";

	for(int i=2, sum; i < term; i++)
	{
		sum = prev_no + curr_no;
		prev_no = curr_no;
		curr_no = sum;
		
		cout << curr_no << "  ";
	}
	
	cout << endl;
	
	
	return 0;
}
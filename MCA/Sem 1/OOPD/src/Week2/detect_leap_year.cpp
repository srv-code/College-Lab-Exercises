// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: To find out if a given year is leap year or not

#include <iostream>
#include <cmath>

using namespace std;

int isLeapYear(const int yr)
{
	int res = 0;
	if(yr <= 0)
		return -1;
	if(yr % 4 == 0)
	{
		res = 1;
		if(yr % 100 == 0)
			if(yr % 400 > 0)
				res = 0;
	}
	return res;
}

int main() 
{
	int year, res;

	// system("clear");

	cout << "Enter year: ";
	cin >> year;

	if((res = isLeapYear(year)) == -1)
	{
		cerr << "Error: Please enter a valid year" << endl;
		return -1;
	}

	cout << "Result: " << (res ? "Leap" : "Not leap") << " year" << endl;

	return 0;
}
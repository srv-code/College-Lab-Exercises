// Author name: Sourav Dey
// Date of creation: 13-Aug-2018
// Week number: 3
// Program name: To find the inverse and double of inverse of an integer

#include <iostream>

#include <cstdlib> // Remove

using namespace std;

int get_inverse(const int n)
{
	int inv = 0;
	for(int num = n < 0 ? -n : n; num > 0; num /= 10)
		inv = (inv * 10) + (num % 10);
	
	return n < 0 ? -inv : inv;
}

int get_double(const int n)
{
	return 2 * n;
}

int main() 
{
	int num, inv;
	system("clear");
	
	cout << "Enter num: ";
	cin >> num;
	
	cout << "Inverse: " << (inv=get_inverse(num)) << endl;
	cout << "Double of inverse: " << get_double(inv) << endl;
	
	
	return 0;
}
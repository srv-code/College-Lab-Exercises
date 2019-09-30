// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: To convert a decimal number to its equivalent binary format and vice versa

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int dec_to_bin(const int n)
{
	int res = 0;
	for(int num = abs(n), p = 1; num > 0; p *= 10, num /= 2)
		res += ( (num % 2) * p );
	return (n < 0) ? -res : res;
}

int bin_to_dec(const int n)
{
	int res = 0;
	for(int num = abs(n), e = 0, d = num % 10; num > 0; e++, num /= 10, d = num % 10)
		if(d > 1)
		{
			cerr << "Error: Invalid binary number!" << endl;
			exit(-1);
		}
		else
			res += (num % 10) * pow(2, e);
	return (n < 0) ? -res : res;	
}

int main()
{
	int conv_mode, continue_input = 1, num_to_conv;

	// system("clear");

	while(continue_input) 
	{
		cout 	<< "Enter conversion mode: \n"
				<< "  1. Decimal to Binary \n"
			 	<< "  2. Binary to Decimal \n" 
			 	<< "Response: ";

		cin >> conv_mode;

		if(continue_input = (conv_mode != 1 && conv_mode != 2))
			cerr << "Error: Please enter a valid response!\n" << endl;
	}

	cout << "Enter number to convert: ";
	cin >> num_to_conv;

	cout << "Result: " << (conv_mode == 1 ? dec_to_bin(num_to_conv) : bin_to_dec(num_to_conv)) << endl;


	return 0;
}
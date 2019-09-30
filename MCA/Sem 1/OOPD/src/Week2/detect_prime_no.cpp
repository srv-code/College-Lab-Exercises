// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: To check if a given integer input is a prime or not

#include <iostream>
#include <cmath>

using namespace std;

int isPrime(const int num)
{
	for(int divisor = 2, n = abs(num), lim = (int)sqrt(n); divisor <= lim; divisor++)
		if(num % divisor == 0)
			return 0;
	return 1;
}

int main() 
{
	int num;

	system("clear");

	cout << "Enter number: ";
	cin >> num;

	cout << "Result: " << (isPrime(num) ? "Prime" : "Non-prime") << endl;

	return 0;
}
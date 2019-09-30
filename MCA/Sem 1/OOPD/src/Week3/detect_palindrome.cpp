// Author name: Sourav Dey
// Date of creation: 13-Aug-2018
// Week number: 3
// Program name: To detect the palindrome of a string

#include <iostream>

#include <cstdlib> // Remove
#include <cstring> // Remove

using namespace std;

int is_palindrome(const char* str)
{
	for(int i=0, sz=strlen(str), j=sz-1, lim=sz/2; i<lim; i++, j--)
		if(str[i] != str[j])
			return 0;
	return 1;
}

int main() 
{
	char str[20];
	
	system("clear");
	
	cout << "Enter a string: ";
	cin >> str;
	
	cout << "Result: " << (is_palindrome(str) ? "Palindrome" : "Not palindrome") << endl;
	
	return 0;
}
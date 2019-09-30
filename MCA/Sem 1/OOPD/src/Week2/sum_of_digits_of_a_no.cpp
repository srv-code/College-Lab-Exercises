// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: Find the sum of individual digits of a positive integer

#include <iostream>

using namespace std;

int main()
{
        int no, sum=0;

        // system("clear");

        cout << "Enter the positive number: ";
        cin >> no;

        while(no > 0)
        {
                sum += no % 10;
                no /= 10;
        }

        cout << "Sum of all digits: " << sum << endl;


        return 0;
}
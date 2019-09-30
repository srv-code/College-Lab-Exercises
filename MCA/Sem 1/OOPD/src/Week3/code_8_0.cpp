#include <iostream>

using namespace std;

int main()
{
	int *p= new int[3],k;
	for(k=0;k<3;k++)
	{
		cout<< "\n Enter a number: ";
		cin>>*p;
		p++;
	}
	p -= 3; //using short-hand operator - =
	cout<< "\n Entered numbers with their address are: \n";
	for (k=0; k<3; k++)
	{
		cout<< "\n\t" << *p << "\t" << p;
		p++;
	}
	p -= 3;
	delete p;
}
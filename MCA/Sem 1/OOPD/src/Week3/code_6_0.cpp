//Code 6.0
#include <iostream>

using namespace std;

int main()
{
	int a=1, b=2;
	int c[3]={3,4,5};
	int *d = &a;
	int &e = a;
	cout << e;
		a = b+c[0];
		b = a;
		c[1] = *d;
		*d = 7;
		e = 8;

		cout << "a=" << a << "\n";
		cout << "b=" << b << "\n";
		cout << "c=" << c << "\n";
		cout << "c[0]=" << c[0] << "\n";
		cout << "c[1]=" << c[1] << "\n";
		cout << "c[2]=" << c[2] << "\n";
		cout << "d=" << d << "\n";
		cout << "*d=" << *d << "\n";
		cout << "e=" << e << "\n";
}
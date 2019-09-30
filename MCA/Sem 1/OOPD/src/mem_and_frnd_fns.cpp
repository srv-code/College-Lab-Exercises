#include <iostream>

using namespace std;


class A
{
                int val;

        public:
                A(int a) { val = a; }
                friend A operator+(A&, A&);
                friend A operator+(int, A&);
                friend A operator+(A&, int);
                A operator-(A);
                void d(const char* m) { cout << m << val << endl; }
};

A operator+(int i, A &a) { a.val += i; return a; }
A operator+(A &a, int i) { a.val += i; return a; }
A operator+(A &a, A &b) { a.val += b.val; return a; }
A A::operator-(A a) { val -= a.val; return *this; }

int main()
{
        A x(0);

        A a(2);
        A b(3);
        A c(4);

        x = 100+a+b+c;
        x.d("x="); a.d("a="); b.d("b="); c.d("c=");

        cout << endl;

        A d(2);
        A e(3);
        A f(4);

        x = d-e-f;
        x.d("x="); d.d("d="); e.d("e="); f.d("f=");


        return 0;
}
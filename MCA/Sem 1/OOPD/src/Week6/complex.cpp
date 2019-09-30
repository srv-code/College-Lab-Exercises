// Author name: Sourav Dey
// Date of creation: 24-SEPT-2018
// Week number: 6
// Program name: Add and subtract two Complex Number objects by overloading + and - operators

#include <iostream>

using namespace std;

class Complex
{
    int real, img;

    public:
        Complex(const int r, const int i)
        {
            real = r;
            img = i;
        }

        Complex operator+(Complex s2)
        {
            return Complex(real + s2.real, img + s2.img);
        }

        Complex operator-(Complex s2)
        {
            return Complex(real - s2.real, img - s2.img);
        }

        void show()
        {
            cout << "Real part:  " << real << ", Imaginary part: " << img << endl;
        }
};

int main()
{
    system("clear");

    int real, img;

    // Take inputs
    cout << "Enter complex number 1: " << endl;    
    cout << "  Real part:       "; cin >> real;
    cout << "  Imaginary part:  "; cin >> img;
    Complex c1(real, img);

    cout << "Enter complex number 2: " << endl;    
    cout << "  Real part:       "; cin >> real;
    cout << "  Imaginary part:  "; cin >> img;
    Complex c2(real, img);

    cout << endl;


    // Perform addition
    cout << "Adding two complex numbers: " << endl;
    cout << "  Complex number 1:  "; c1.show();
    cout << "  Complex number 2:  "; c2.show();
    cout << "  Summation:  "; (c1 + c2).show();
    cout << endl;

    // Perform subtraction
    cout << "Subtracting two complex numbers: " << endl;
    cout << "  Complex number 1:  "; c1.show();
    cout << "  Complex number 2:  "; c2.show();
    cout << "  Difference:  "; (c1 - c2).show();
    cout << endl;


    return 0;
}
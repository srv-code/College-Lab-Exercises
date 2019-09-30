// Author name: Sourav Dey
// Date of creation: 27-AUG-2018
// Week number: 4
// Program name: Create a Complex class and its two overloaded functions to add one integer and one Complex number and two Complex numbers

#include <iostream>
#include <cstdlib> // remove

using namespace std;

class Complex 
{
    int real, img;

    public:
        Complex() 
        {
            real = 0;
            img = 0;
        }

        Complex(const int r, const int i)
        {
            real = r;
            img = i;
        } 

        Complex add(const int s1, Complex s2) 
        {
            return Complex(s2.real + s1, s2.img);
        }

        // Overloaded
        Complex add(const Complex s1, const Complex s2)
        {
            return Complex(s1.real + s2.real, s1.img + s2.img);
        }

        void show() 
        {
            cout << "Real part:  " << real << ", Imaginary part: " << img << endl;
        }
};

int main() 
{
    system("clear");
    
    Complex c[2];
    int i, real, img;

    // Take inputs
    for(i=0; i<2; i++) {
        cout << "Input complex number " << (i+1) << ": \n";
        cout << "  Real part:  "; cin >> real;
        cout << "  Imaginary part:  "; cin >> img;
        c[i] = Complex(real, img);
    }

    cout << "Input an integer:  "; cin >> i;
    cout << endl;

    // Perform addition
    cout << "Adding two complex numbers: \n";
    cout << "  Complex number 1:  "; c[0].show();
    cout << "  Complex number 2:  "; c[1].show();
    cout << "  Summation:  "; (c[0].add(c[0], c[1])).show();
    cout << endl;

    cout << "Adding an integer and a complex number: \n";
    cout << "  Integer:  " << i << "\n";
    cout << "  Complex number:  "; c[0].show();
    cout << "  Summation:  "; (c[0].add(i, c[0])).show();
    

    return 0;
}
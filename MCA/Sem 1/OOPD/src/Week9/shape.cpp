// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Week number: 9
// Program name: Shape as base class and Rectangle and Triangle as derived classes

#include <iostream>
#include <iomanip> // for setpresicion
#include <cstdlib> // for personal sys compatibility

using namespace std;


class Shape 
{
	protected:
		double dimension_1, dimension_2, area;
		virtual double compute_area() = 0;

	public:
		virtual void display_area() = 0;

		void get_data() 
		{
			cout << "  Dimension 1:  "; cin >> dimension_1;
			cout << "  Dimension 2:  "; cin >> dimension_2;
		}
};

class Rectangle: public Shape 
{
		double compute_area() 
		{
			return (area = dimension_1 * dimension_2);
		}

	public:
		void display_area() 
		{
			cout << setprecision(4) << compute_area() << " square units";
		}
};

class Triangle: public Shape
{
		double compute_area() 
		{
			return (area = dimension_1 * dimension_2 * 0.5);
		}

	public:
		void display_area() 
		{
			cout << setprecision(4) << compute_area() << " square units";
		}	
};


int main() 
{
	system("clear");

	Shape* shape;

	Rectangle rectangle;
	shape = &rectangle;
	cout << "\nInput dimensions for rectangle: \n";
	shape->get_data();
	cout << "Area of rectangle: ";
	shape->display_area();
	cout << endl;

	Triangle triangle;
	shape = &triangle;
	cout << "\nInput dimensions for triangle: \n";
	shape->get_data();
	cout << "Area of triangle: ";
	shape->display_area();
	cout << endl;

	return 0;
}
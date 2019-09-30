// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Week number: 8
// Proram name: Create, update and display information from multiple derived class: Master class 

#include <iostream> 
#include <string>
#include <cstdlib> // for persoanl sys compatibility
#include <cstdio> // for debugging: printf
#include <iomanip> // for setprecision

using namespace std;

const bool DEBUG_ENABLED = 0; // DEBUG


class Employee
{
	protected: 
		string name;
		int code;
};

class Account: virtual protected Employee
{
	protected:
		float pay;
};

class Admin: virtual protected Employee
{
	protected:
		int experience_yrs;
};

class Master: private Account, private Admin
{
	public:
		Master() {}

		Master(	const string nm,
				const int c, 
				const float p,
				const int eyrs) 
		{
			name = nm;
			code = c;
			pay = p;
			experience_yrs = eyrs;
		}

		void update_pay(const float p) { pay = p; }
		void update_exp_yrs(const float y) { experience_yrs = y; }

		void display_information() 
		{
			cout 	<< "Master record information: "
					<< "\n  Code: " << code 
					<< "\n  Name:  " << name
					<< "\n  Experience years:  " << experience_yrs
					<< "\n  Pay: $" << pay
					<< endl;
		}
};

int main() 
{
	system("clear");

	int code, eyrs;
	string name;
	float pay;

	cout 	<< "Enter master details: \n"
			<< "  Code:  "; cin >> code;
	cout << "  Name:  "; cin >> name;
	cout << "  Experience years:  "; cin >> eyrs;
	cout << "  Pay:  $"; cin >> pay;

	Master master(name, code, pay, eyrs);

	cout << "Master record created.\n" << endl;
	master.display_information();
	cout << endl;

	cout << "Enter new pay:  $"; cin >> pay;
	master.update_pay(pay);
	cout << "Enter new experience years: "; cin >> eyrs;
	master.update_exp_yrs(eyrs);

	cout << "Master record updated.\n" << endl;
	master.display_information();


	return 0;
}
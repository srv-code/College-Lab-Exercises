// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Week number: 7
// Proram name: College employee database

#include <iostream> 
#include <string> 
#include <cstdlib> // For personal sys compatibility

using namespace std;


class Employee 
{
		int emp_code;
		string emp_name;

	protected:
		Employee() {}

		Employee(const int c, const string nm)
		{
			emp_code = c;
			emp_name = nm;
		}

		void display_details() 
		{
			cout	<< "\n  Emp Code:  " << emp_code
					<< "\n  Name:  " << emp_name;
		}
};

class Faculty : protected Employee
{
		string qualification;
		int yrs_of_exp;

	protected:
		Faculty() {}

		Faculty(	const int c, 
					const string nm, 
					const string q, 
					const int eyrs) : Employee(c, nm)
		{
			qualification = q;
			yrs_of_exp = eyrs;
		}

		void display_details() 
		{
			Employee::display_details();
			cout	<< "\n  Qualification:  " << qualification
					<< "\n  Years of experience:  " << yrs_of_exp;
		}
};

class Non_Teaching : private Employee
{
		char grade;

	public:
		Non_Teaching() {}

		Non_Teaching(	const int c, 
						const string nm,
						const char g) : Employee(c, nm)
		{
			grade = g;
		}

		void display_details()
		{
			Employee::display_details();
			cout	<< "\n  Grade:  " << grade << endl;
		}
};

class Permanent : private Faculty
{
		float basic_pay, acad_allowance;

	public:
		Permanent() {}

		Permanent(	const int c,
					const string nm,
					const string q,
					const int eyrs,
					const float bpay) : Faculty(c, nm, q, eyrs)
		{
			basic_pay = bpay;
			acad_allowance = bpay * 0.25; // 25% of basic pay
		}

		void display_details() 
		{
			Faculty::display_details();
			cout	<< "\n  Basic pay:  $" << basic_pay 
					<< "\n  Academic allowance:  $" << acad_allowance << endl;
		}
};

class Contract : private Faculty 
{
		int prob_years;

	public: 
		Contract() {}
		
		Contract(	const int c,
					const string nm,
					const string q,
					const int eyrs,
					const int pyrs) : Faculty(c, nm, q, eyrs)
		{
			prob_years = pyrs;
		}

		void display_details() 
		{
			Faculty::display_details();
			cout	<< "\n  Probation years:  " << prob_years << endl;
		}
};

int main()
{
	system("clear");

	int ecode, eyrs, pyrs; 
	string ename, quali;
	char grade;
	float bpay;


	cout 	<< "Enter non-teaching staff details: \n"
			<< "  Emp code:  "; cin >> ecode;
	cout << "  Name:  "; cin >> ename;
	cout << "  Grade:  "; cin >> grade;
	cout << endl;

	Non_Teaching nteaching_staff(ecode, ename, grade);


	cout 	<< "Enter permanent staff details: \n"
			<< "  Emp code:  "; cin >> ecode;
	cout << "  Name:  "; cin >> ename;
	cout << "  Qualification:  "; cin >> quali;
	cout << "  Years of experience:  "; cin >> eyrs;
	cout << "  Basic Pay:  "; cin >> bpay;
	cout << endl;

	Permanent perm_staff(ecode, ename, quali, eyrs, bpay);


	cout 	<< "Enter permanent staff details: \n"
			<< "  Emp code:  "; cin >> ecode;
	cout << "  Name:  "; cin >> ename;
	cout << "  Qualification:  "; cin >> quali;
	cout << "  Years of experience:  "; cin >> eyrs;
	cout << "  Probation years:  "; cin >> pyrs;
	cout << endl;

	Contract cont_staff(ecode, ename, quali, eyrs, pyrs);

	cout << "Non-Teaching staff details:";
	nteaching_staff.display_details();
	cout << endl;

	cout << "Permanent staff details:";
	perm_staff.display_details();
	cout << endl;

	cout << "Contract staff details:";
	cont_staff.display_details();
	cout << endl;



	return 0;
}
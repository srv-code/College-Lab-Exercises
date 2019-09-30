// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Week number: 9
// Program name: Employee, Education, Laborer, Scientist, Manager

#include <iostream> 
#include <string>
#include <cstdlib> // for personal sys compatibility

using namespace std;

const bool DEBUG_ENABLED = 0; // DEBUG


class Employee
{
	protected:
		int empno;
		string ename;
		float pay;

	public: 
		virtual void display_emp_info() = 0;
};

class Laborer: public Employee
{
		int workshop_code;
		string machine_expertise;

	public: 
		Laborer(	const int eno,
					const string nm,
					const float p,
					const int wcode,
					const string mexpt) 
		{
			empno = eno;
			ename = nm;
			pay = p;
			workshop_code = wcode;
			machine_expertise = mexpt;
		}

		void display_emp_info() 
		{
			cout	<< "\n  Employee number:  " << empno
					<< "\n  Name: " << ename
					<< "\n  Pay:  $" << pay 
					<< "\n  Workshop code:  " << workshop_code
					<< "\n  Machine expertise:  " << machine_expertise;
		}
};

class Education
{
	protected: 
		string qualification;
		int pass_out_year;

	public: 
		virtual void display_educational_info() = 0;
};

class Scientist: public Employee, public Education
{
		string research_dept_name;

	public: 
		Scientist(	const int eno,
					const string nm,
					const float p,
					const string q,
					const int pyr,
					const string rdept)
		{
			empno = eno;
			ename = nm;
			pay = p;
			qualification = q;
			pass_out_year = pyr;
			research_dept_name = rdept;
		}

		void display_emp_info() 
		{
			cout	<< "\n  Employee number:  " << empno
					<< "\n  Name: " << ename
					<< "\n  Pay:  $" << pay;
		}

		void display_educational_info() 
		{
			cout	<< "\n  Research department name: " << research_dept_name
					<< "\n  Qualification:  " << qualification
					<< "\n  Pass out year: " << pass_out_year;
		}
};

class Manager: public Employee, public Education
{
		string mgmt_dept;

	public: 
		Manager(	const int eno,
					const string nm,
					const float p,
					const string q,
					const int pyr,
					const string mdept)
		{
			empno = eno;
			ename = nm;
			pay = p;
			qualification = q;
			pass_out_year = pyr;
			mgmt_dept = mdept;
		}

		void display_emp_info() 
		{
			cout	<< "\n  Employee number:  " << empno
					<< "\n  Name: " << ename
					<< "\n  Pay:  $" << pay;
		}

		void display_educational_info() 
		{
			cout	<< "\n  Management department: " << mgmt_dept
					<< "\n  Qualification:  " << qualification
					<< "\n  Pass out year: " << pass_out_year;
		}
};



int main() 
{
	system("clear");

	int eno, workshop_code, pass_out_year;
	string name, machine_expertise, qualification, research_dept_name, mgmt_dept;
	float pay;


	cout << "\nEnter laborer details: \n";
	cout << "  Employee number:  "; cin >> eno;
	cout << "  Name: "; cin >> name;
	cout << "  Pay: $"; cin >> pay;
	cout << "  Workshop code: "; cin >> workshop_code;
	cout << "  Machine expertise: "; cin >> machine_expertise;

	Laborer laborer(eno, name, pay, workshop_code, machine_expertise);

	
	cout << "\nEnter scientist details: \n";
	cout << "  Employee number:  "; cin >> eno;
	cout << "  Name: "; cin >> name;
	cout << "  Pay: $"; cin >> pay;
	cout << "  Qualification: "; cin >> qualification;
	cout << "  Pass out year: "; cin >> pass_out_year;
	cout << "  Research department name: "; cin >> research_dept_name;

	Scientist scientist(eno, name, pay, qualification, pass_out_year, research_dept_name);

	cout << "\nEnter manager details: \n";
	cout << "  Employee number:  "; cin >> eno;
	cout << "  Name: "; cin >> name;
	cout << "  Pay: $"; cin >> pay;
	cout << "  Qualification: "; cin >> qualification;
	cout << "  Pass out year: "; cin >> pass_out_year;
	cout << "  Management department: "; cin >> mgmt_dept;

	Manager manager(eno, name, pay, qualification, pass_out_year, mgmt_dept);


	Employee *emp;
	Education *ed; 

	emp = &laborer;
	cout << "\n\nLaborer information:";
	emp->display_emp_info();


	emp = &scientist;
	ed = &scientist;
	cout << "\n\nScientist information:";
	emp->display_emp_info();
	ed->display_educational_info();

	emp = &manager;
	ed = &manager;
	cout << "\n\nManager information:";
	emp->display_emp_info();
	ed->display_educational_info();

	cout << endl;


	return 0;
}
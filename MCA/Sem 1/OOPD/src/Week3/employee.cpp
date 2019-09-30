#include <iostream>
#include <cstdlib> // REMOVE

using namespace std;

struct EMPLOYEE
{
	int Employee_Number;
	char Employee_Name[20];
	float Basic, DA = 12.0, IT = 18.0, Net_Sal;

	void read_data() 
	{
		cout << "  Number: ";
		cin >> Employee_Number;
		cout << "  Name: ";
		cin >> Employee_Name;
		cout << "  Basic Pay: ";
		cin >> Basic;
	}

	void calculate_net_salary() 
	{
		Net_Sal  =  Basic + (Basic * DA/100);
		Net_Sal -= (Net_Sal * IT / 100);
	}

	void display_net_salary() 
	{
		calculate_net_salary();
		cout << Net_Sal << endl;
	}
};

int main() 
{
	int n;
	system("clear");

	cout << "Enter value of n: "; 
	cin >> n;

	EMPLOYEE emps[n];

	for(int i=0; i<n; i++)
	{
		cout << "Enter information of employee " << i+1 << ": \n";
		emps[i].read_data();
	}

	cout << "Net salaries: \n";
	for(int i=0; i<n; i++)
	{
		cout << "Employee " << i+1 << ": ";
		emps[i].display_net_salary();
	}

	return 0;
}
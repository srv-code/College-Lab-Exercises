// Author name: Sourav Dey
// Date of creation: 22-OCT-2018
// Week number: 10
// Program name: Employee database

#include <iostream>
#include <fstream>
// #include <iomanip>
#include <cstring>
#include <cstdlib> // for personal sys compatibility
// #include <cstdio> // for debugging

using namespace std;


class Employee
{
    private:
        static int next_emp_id; // starts from 0
        char name[20], dname[10], desig[10];
        int id;
        float basic_pay, da, hra, gross_pay, it, net_pay;

    public:
        void accept_data();
        void display_salary_slip();
        bool operator==(const int eid);
};

class Employee_Database
{
    private:
        char db_fname[10];
        ofstream fout;
        ifstream fin;

    public:
        Employee_Database(const char* fname);
        void write(const Employee e);
        Employee* search(const int eid);
};


int Employee::next_emp_id; // starts from 0

void Employee::accept_data()
{
    cout << "Enter employee details: \n";
    cout << "  Name:  "; cin.getline(name, sizeof(name));
    cout << "  Designation:  "; cin.getline(desig, sizeof(desig));
    cout << "  Department name:  "; cin.getline(dname, sizeof(dname));
    cout << "  Basic salary:  "; cin >> basic_pay;

    // salary calculations
    da = basic_pay * 0.2; // 20 % of basic pay
    hra = basic_pay * 0.15; // 15 % of basic pay
    gross_pay = basic_pay + da + hra; // 15 % of basic pay
    it = basic_pay * 0.12; // 12% of basic pay
    net_pay = gross_pay - it;

    id = ++next_emp_id;
    cout << "  Employee ID:  " << id << endl;
}

void Employee::display_salary_slip()
{
    cout    << "Salary slip:"
            << "\n  Employee ID:  " << id
            << "\n  Name:  " << name
            << "\n  Department name:  " << dname
            << "\n  Designation:  " << desig
            << "\n  Basic pay:  Rs. " << basic_pay
            << "\n  Dearness allowance:  Rs. " << da
            << "\n  House rent allowance:  Rs. " << hra
            << "\n  Income tax:  Rs. " << it
            << "\n  Gross pay:  Rs. " << gross_pay
            << "\n  Net pay:  Rs. " << net_pay
            << endl;

}

bool Employee::operator==(const int eid)
{
    return id == eid;
}

Employee_Database::Employee_Database(const char* fname)
{
    strcpy(db_fname, fname);
}

void Employee_Database::write(const Employee e)
{
    fout.open(db_fname, ios::app);
    fout.write((char*) &e, sizeof(Employee));
    fout.close();
}

Employee* Employee_Database::search(const int eid)
{
    fin.open(db_fname);

    Employee *e = NULL, emp;
    bool found = false;
    while(fin && !found) {
        fin.read((char*) &emp, sizeof(Employee));
        found = (emp == eid);
    }

    if(found)
        e = new Employee(emp);

    fin.close();

    return e;
}



int main()
{
    system("clear");

    Employee e;
    Employee_Database db("emp.db");
    char resp;

    do {
        e.accept_data();
        db.write(e);

        cout << "\nEnter another employee details? [y for yes]:  ";
        cin >> resp;
        cin.ignore();
    } while(resp == 'y');

    int eid;
    cout << "\nEnter employee ID to print salary details for:  ";
    cin >> eid;
    Employee* emp = db.search(eid);

    if(emp == NULL)
        cout << "Error: Employee not found!" << endl;
    else
        emp->display_salary_slip();


    return 0;
}
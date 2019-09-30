// Author Name: Sourav Dey
// Date of creation: 30-Jul-2018
// Week number: 1
// Program name: ###


#include <iostream>

using namespace std;

void show_stud_info(    const char*,
                        const char*,
                        const char*,
                        const char*,
                        const char*);

int main()
{
        system("clear");

        show_stud_info("Sourav Dey", "MCA", "03-08-2015", "Maths, OOPD, ADBMS, SEPM, ADAA", "Computer Applications");

        show_stud_info("Amir Saha", "M Tech", "01-08-2015", "Maths, DE, SEPM, ADSA, OOPD", "Computer Science");

        return 0;
}


void show_stud_info(    const char* name,
                        const char* branch,
                        const char* doj,
                        const char* subs,
                        const char* dept)
{
        cout << "Name: " << name << "\n";
        cout << "Branch: " << branch << "\n";
        cout << "Date of Joining: " << doj << "\n";
        cout << "Subjects: " << subs << "\n";
        cout << "Department: " << dept << "\n";
        cout << "College: Manipal Institute of Technology, Manipal \n";
        cout << "University: Manipal University \n";
        cout << "\n";
}
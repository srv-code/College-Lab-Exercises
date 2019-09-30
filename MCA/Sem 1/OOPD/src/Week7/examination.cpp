// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Week number: 7
// Proram name: Example of declaring the examination results.

#include <iostream> 
#include <string>
#include <cstdlib> // for persoanl sys compatibility
#include <cstdio> // for debugging: printf
#include <iomanip> // for setprecision

using namespace std;

const bool DEBUG_ENABLED = 0; // DEBUG

class Student
{
	protected:
		int roll_no;
		string name, branch;
		int year_of_joining;

		Student() {}
		Student(	const int rno, 
					const string nm, 
					const string br, 
					const int yr) 
		{
			if(DEBUG_ENABLED)
				printf("\n  // Student cons called with args: ");

			roll_no = rno;
			name = nm;
			branch = br;
			year_of_joining = yr;

			if(DEBUG_ENABLED)
				printf("roll_no=%d, name=%s, branch=%s, year_of_joining=%d \n", rno, name.c_str(), branch.c_str(), year_of_joining);
		}
};

class Exam : protected Student
{
	protected: 
		float marks[6];

		Exam() {}
		Exam(	const int rno, 
				const string nm, 
				const string br, 
				const int yr, 
				const float m[6]) : Student(rno, nm, br, yr)
		{
			if(DEBUG_ENABLED)
				printf("  // Exam cons called with args: \n");

			for(int i=0; i<6; i++)
				marks[i] = m[i];

			if(DEBUG_ENABLED) {
				printf("  //   marks[]: \n");
				for(int i=0; i<6; i++)
					printf("  //     marks[%d]=%f \n", i, marks[i]);
			}
		}
};

class Result : private Exam 
{
	private: 
		float total_marks;
		string grade;

		void calculate_total_marks()
		{
			total_marks = 0.0;
			for(int i=0; i<6; i++) {
				total_marks += marks[i];
				if(DEBUG_ENABLED) {
					printf("  // i=%d: total_marks=%f, marks[i]=%f \n", i, total_marks, marks[i]);
				}
			}
		}

		void calculate_grade()
		{
			if(total_marks >= 540) // 90% 
				grade = "A+";
			else if(total_marks >= 480) // 80%
				grade = "A";
			else if(total_marks >= 420) // 70%
				grade = "B";
			else if(total_marks >= 360) // 60%
				grade = "C";
			else if(total_marks >= 300) // 50%
				grade = "D";
			else if(total_marks >= 240) // 40%
				grade = "E";
			else 
				grade = "F";
		}

	public: 
		Result() {}
		Result(	const int rno, 
				const string nm, 
				const string br, 
				const int yr, 
				const float m[6]) : Exam(rno, nm, br, yr, m)
		{
			if(DEBUG_ENABLED)
				printf("  // Result cons called \n");

			calculate_total_marks();
			calculate_grade();

			if(DEBUG_ENABLED)
				printf("  // After calc: total_marks=%f, grade=%s \n", total_marks, grade.c_str());
		}

		// Getters
		string get_grade() { return grade; }
		float get_total_marks() { return total_marks; }
};

int main() 
{
	system("clear");

	int rno; 
	string nm, br; 
	int yr; 
	float m[6];
	bool err;

	cout << "Input student details: " << endl;
	do {
		cout << "  Roll number:  "; cin >> rno;
		if(err = (rno < 1 || rno > 100))
			cerr << "Error: Enter value between 1 and 100" << endl;
	} while(err);

	cout << "  Name:  "; cin >> nm;

	cout << "Input academic details: " << endl;
	do {
		cout << "  Branch:  "; cin >> br;
		// if(err = (br.compare("BTech") && br.compare("BCA") && !br.compare("MTech") && br.compare("MCA")))
		if(err = (br != "BTech" && br != "BCA" && br != "MTech" && br != "MCA"))
			cerr << "Error: Enter a value within: BTech, BCA, MTech, MCA" << endl;
	} while(err);

	do {
		cout << "  Year of joining:  "; cin >> yr;
		if(err = (yr < 2000 || yr > 2018))
			cerr << "Error: Enter a value between 2000 and 2018" << endl;
	} while(err);

	cout << "  Marks in 6 subjects:" << endl;
	for(int i=0; i<6; i++) {
		do {
			cout << "    Subject " << (i+1) << ":  ";
			cin >> m[i];

			if(err = (m[i] < 0.0 || m[i] > 100.0))
				cerr << "Error: Enter a value between 0 and 100" << endl;
		} while(err);
	}

	Result result(rno, nm, br, yr, m);
	cout 	<< "Result:"
			<< "\n  Total marks: " << setprecision(4) << result.get_total_marks()
			<< "\n  Grade:  " << result.get_grade() 
			<< endl;


	return 0;
}
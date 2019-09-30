// Author name: Sourav Dey
// Date of creation: 01-OCT-2018
// Week number: 8
// Proram name: New scheme of evaluation of student’s performance is formulated that gives weightage for sports

#include <iostream> 
#include <string> 
#include <iomanip> // for setprecision
#include <cstdlib> // for personal sys compatibility
#include <cstdio> // for debugging: printf

using namespace std;

const bool DEBUG_ENABLED = 0;


class Student 
{
	protected: 
		int rollno;	
		string name, branch;

		Student() 
		{
			if(DEBUG_ENABLED) {
				printf("  // Const Student() called \n");
			}
		}

		// Student(const int rno, const string nm, const string br) 
		// {
		// 	if(DEBUG_ENABLED) {
		// 		printf("  // Const Student(...) called with args: rno=%d, nm=%s, br=%s \n",
		// 					rno, nm.c_str(), br.c_str());
		// 	}

		// 	rollno = rno;
		// 	name = nm;
		// 	branch = br;
		// }

		virtual void display_details() = 0;
};

class Exam : protected virtual Student 
{
	protected:
		float sub_marks[5];

		Exam() 
		{
			if(DEBUG_ENABLED) {
				printf("  // Const Exam() called \n");
			}
		}

		// Exam(const int rno, const string nm, const string br, const float m[5]) : Student(rno, nm, br) 
		// {
		// 	if(DEBUG_ENABLED) {
		// 		printf("  // Const Student(...) called with args: rno=%d, nm=%s, br=%s, m={",
		// 					rno, nm.c_str(), br.c_str());
		// 		for(int i=0; i<5; i++) {
		// 			printf("%.2f%c", m[i], i==4 ? '}' : ',');
		// 		}
		// 		printf(" \n");
		// 	}

		// 	for(int i=0; i<5; i++) {
		// 		sub_marks[i] = m[i];
		// 	}
		// }
};

class Sports : protected virtual Student 
{
	protected:
		float sports_marks;

		Sports() 
		{
			if(DEBUG_ENABLED) {
				printf("  // Const Sports() called \n");
			}
		}

		// Sports(const int rno, const string nm, const string br, const float m) : Student(rno, nm, br) 
		// {
		// 	if(DEBUG_ENABLED) {
		// 		printf("  // Const Sports(...) called with args: rno=%d, nm=%s, br=%s, m=%.2f \n",
		// 					rno, nm.c_str(), br.c_str(), m);
		// 	}
		// 	sports_marks = m;
		// }
};

class Result : private Exam, private Sports
{
		float total_marks, marks_percentage;
		string grade;

		// sets total_marks & marks_percentage
		void calculate_total_marks() 
		{
			total_marks = 0;
			for(int i=0; i<5; i++) {
				total_marks += sub_marks[i];
			}
			total_marks += sports_marks;
			marks_percentage = total_marks / 6;
		}

		void calculate_grade()
		{
			if(marks_percentage >= 90) 
				grade = "A+";
			else if(marks_percentage >= 80)
				grade = "A";
			else if(marks_percentage >= 70)
				grade = "B";
			else if(marks_percentage >= 60)
				grade = "C";
			else if(marks_percentage >= 50)
				grade = "D";
			else if(marks_percentage >= 40)
				grade = "E";
			else 
				grade = "F";
		}

	public:
		Result() 
		{
			if(DEBUG_ENABLED) {
				printf("  // Const Result() called \n");
			}
		}

		Result(	const int rno, 
				const string nm, 
				const string br, 
				const float subm[5], 
				const float sm) //: Exam(rno, nm, br, subm), Sports(rno, nm, br, sm)
		{
			if(DEBUG_ENABLED) {
				printf("  // Const Result(...) called with args: rno=%d, nm=%s, br=%s, subm={",
							rno, nm.c_str(), br.c_str());
				for(int i=0; i<5; i++) {
					printf("%.2f%c", subm[i], i==4 ? '}' : ',');
				}
				printf(", sm=%.2f \n", sm);
			}

			// set values to all inherited and curr object local variables
			rollno = rno;
			name = nm;
			branch = br;
			for(int i=0; i<5; i++)
				sub_marks[i] = subm[i];
			sports_marks = sm;

			calculate_total_marks();
			calculate_grade();
		}

		void display_details() 
		{
			cout 	<< "Result:"
					<< "\n  Roll number:  " << Exam::rollno
					<< "\n  Name:  " << Exam::name 
					<< "\n  Branch:  " << Exam::branch 
					<< "\n  Total marks:  " << setprecision(4) << total_marks
					<< "\n  Marks percentage:  " << setprecision(4) << marks_percentage << "%"
					<< "\n  Grade:  " << grade 
					<< endl;
		}
};


int main() 
{
	system("clear");

	int rno; 
	string nm, br; 
	int yr; 
	float subm[5], sportsm, m;
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
		if(err = (br != "BTech" && br != "BCA" && br != "MTech" && br != "MCA"))
			cerr << "Error: Enter a value within: BTech, BCA, MTech, MCA" << endl;
	} while(err);

	do {
		cout << "  Year of joining:  "; cin >> yr;
		if(err = (yr < 2000 || yr > 2018))
			cerr << "Error: Enter a value between 2000 and 2018" << endl;
	} while(err);

	cout << "  Marks in 5 subjects:" << endl;
	for(int i=0; i<6; i++) {
		do {
			if(i<5) { // last element: sports marks
				cout << "    Subject " << (i+1) << ":  ";
				cin >> m;
				subm[i] = m;
			} else {
				cout << "  Marks in sports:  ";
				cin >> m;
				sportsm = m;
			}

			if(err = (m < 0 || m > 100))
				cerr << "Error: Enter a value between 0 and 100" << endl;
		} while(err);
	}
	cout << endl;

	Result result(rno, nm, br, subm, sportsm);
	result.display_details();


	return 0;
}
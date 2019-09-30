// Author name: Sourav Dey
// Date of creation: 06-Aug-2018
// Week number: 2
// Program name: To design a student score card based on the provided grading criteria

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char get_score_grade(const float marks)
{
	if(marks >= 90.0f)
		return 'A';
	if(marks > 80.0f)
		return 'B';
	if(marks > 61.0f)
		return 'C';
	if(marks > 51.0f)
		return 'D';
	if(marks > 41.0f)
		return 'E';
	return 'F';
}

int main() 
{
	string name;
	int reg_no, joining_year, sem_no, sub_count = 5, marks_list[5], marks_total = 0;
	char* sub_list[] = { "Object Oriented Programming & Design", "ADBMS", "ADSA", "Computational Mathematics", "SEPM" };	
	float marks_avg;

	// system("clear");

	cout << "Enter student details:" << endl;
	cout << "  Name: "; getline(cin, name);
	cout << "  Registration number: "; cin >> reg_no;
	cout << "  Year of joining: "; cin >> joining_year;
	cout << "  Semester number: "; cin >> sem_no;
	cout << "  Enter marks of subjects:" << endl;

	for(int i=0; i<sub_count; i++)
	{
		printf("    [%d]  %40s: ", i+1, sub_list[i]);
		cin >> marks_list[i];
		marks_total += marks_list[i];
	}

	marks_avg = (float)marks_total / (float)sub_count;

	cout << "----------------------------------------------------------------------------\n";
	cout << "Score Card for Student: " << name << "\n\n";
	cout << "Registration Number: " << reg_no << "\t\t Semester: " << sem_no << "\t Year: " << joining_year << "\n";
	cout << "Grade Assigned: \n\n";
	cout << "Serial No. \t\t Subject Name \t\t\t Marks Scored (out of 100) \n";
	cout << "----------------------------------------------------------------------------\n";
	
	for(int i=0 ; i<sub_count; i++)
		printf("%d \t\t %-40s \t\t %3d \n", i+1, sub_list[i], marks_list[i]);

	printf("  \t\t    \t\t    \t\t   %8s: \t %3d \n", "Total", marks_total);
	printf("  \t\t    \t\t    \t\t   %8s: \t %3.1f \n", "Average", marks_avg);
	printf("  \t\t    \t\t    \t\t   %8s: \t %c \n", "Grade", get_score_grade(marks_avg));

	printf("  Signatures:\n\n");
	printf("  \t Student: \t\t\t\t\t HOD\n\n");
	cout << "----------------------------------------------------------------------------\n";

	return 0;
}
/**
	Inheritance - 2
	Create three classes as per the following specifications:
		• Student: Data members are Register Number, Name, Course and Semester.
		• Exam (derived from class Student): Data members are the marks scored in three subjects.
		• Result (derived from class Exam): Data members are Total Marks and Grade.
	Input the relevant data of one student (in the main() method) and process the result.
*/

import java.util.Scanner;

public class Prg13 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter student details:");
		System.out.print  ("  Registration number:  "); int regNo = sc.nextInt();
		System.out.print  ("  Name:  "); String name = sc.next();
		System.out.print  ("  Course:  "); String course = sc.next();
		System.out.print  ("  Semester:  "); int semester = sc.nextInt();
		System.out.println("Enter exam details:");
		System.out.print  ("  Subject 1 Marks:  "); float marks1 = sc.nextFloat();
		System.out.print  ("  Subject 2 Marks:  "); float marks2 = sc.nextFloat();
		System.out.print  ("  Subject 3 Marks:  "); float marks3 = sc.nextFloat();
		
		Result result = new Result(regNo, semester, name, course, marks1, marks2, marks3);
		result.calc();
		System.out.println("Result:");
		System.out.println("  Total marks:  " + result.getTotalMarks());
		System.out.println("  Grade:        " + result.getGrade());
	}
}

class Student {
	private int regNo, semester;
	private String name, course;
	
	Student(int regNo, int semester, String name, String course) {
		this.regNo = regNo;
		this.semester = semester;
		this.name = name;
		this.course = course;
	}
}

class Exam extends Student {
	float marks1, marks2, marks3;
	
	Exam(int regNo, int semester, String name, String course, float m1, float m2, float m3) {
		super(regNo, semester, name, course);
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
}

class Result extends Exam {
	float totalMarks;
	char grade;
	
	Result(int regNo, int semester, String name, String course, float m1, float m2, float m3) {
		super(regNo, semester, name, course, m1, m2, m3);
	}
	
	void calc() {
		totalMarks = marks1 + marks2 + marks3;
		float percentage = totalMarks/3;
		
		if(percentage >= 90.0f) grade = 'O';
		else if(percentage >= 80.0f) grade = 'A';
		else if(percentage >= 70.0f) grade = 'B';
		else if(percentage >= 60.0f) grade = 'C';
		else if(percentage >= 50.0f) grade = 'D';
		else if(percentage >= 40.0f) grade = 'E';
		else grade = 'F';
	}
	
	float getTotalMarks() { return totalMarks; }
	char getGrade() { return grade; }
}
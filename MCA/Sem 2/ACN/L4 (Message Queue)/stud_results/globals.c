/* 13) Write a client server program to 
		accept an array of student data 
		and return the results to the 
		client. The student details should 
		be a structure data type containing 
		the following elements:
			Registration Number
			Student Name 
			Marks in 3 subjects
			
	>> Global
*/


#define MAX_ARR_SZ 20
#define MAX_NAME_SZ 20

struct stud_data {
	int reg_no; // Registration Number
	char name[MAX_NAME_SZ]; // Student Name 
	float marks[3]; // Marks in 3 subjects
	float total_marks;
	float percentage;
	char grade;
};

struct msg_buf {
	long mtype;
	struct stud_data data[MAX_ARR_SZ];
	int alen;
};

const long QUERY_MTYPE = 11;
const long RESP_MTYPE = 10;

create table empsal 
(
	empno				number(4) primary key, 
	empname				varchar2(10), 
	basic_salary		number(7,2) not null,
	HRA					number(7,2),
	DA					number(7,2),
	Gross_Salary		number(7,2),
	PF					number(7,2),
	Net_Salary			number(7,2)
);
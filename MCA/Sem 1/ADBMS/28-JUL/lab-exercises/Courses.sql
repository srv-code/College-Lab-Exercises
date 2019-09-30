create table Courses 
(
	CID varchar2 (9) unique,
	C_Name varchar2(25) not null,
	Creadits number(2),
	Duration number(2)
);


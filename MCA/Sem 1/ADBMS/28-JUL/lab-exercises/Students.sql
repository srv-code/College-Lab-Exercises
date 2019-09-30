create table Students 
(
	SID char(9) primary key,
	Name varchar2(25) not null,
	Age number(2),
	Email varchar2(10) unique
);
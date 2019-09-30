create table stud 
(
	regno number(3) primary key,
	mark1 number(2),
	mark2 number(2),
	avg_mark number(3,1),
	grade char(2)
);

insert into stud (regno, mark1, mark2) values (101, 69, 79);
insert into stud (regno, mark1, mark2) values (102, 59, 89);
insert into stud (regno, mark1, mark2) values (104, 89, 99);
insert into stud (regno, mark1, mark2) values (106, 87, 66);
insert into stud (regno, mark1, mark2) values (108, 89, 69);
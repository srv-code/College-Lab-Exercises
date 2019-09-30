/* 
create table emp1 
(
	empno number(6) constraint emp_empno_PK primary key,
	ename varchar2(20),
	job varchar2(20),
	hiredate date,
	sal number(6),
	bonus number(5),
	deptno number(3)
);
*/


/* 
insert into emp1 values (101, 'AAA', null, null, 1234, null, 10);
insert into emp1 values (102, 'BBB', null, null, 1234, null, 10);
insert into emp1 values (103, 'CCC', null, null, 1234, null, 10);
insert into emp1 values (104, 'DDD', null, null, 1234, null, 10);
insert into emp1 values (105, 'EEE', null, null, 1234, null, 10); 
*/

/* 
select * from emp1;
*/
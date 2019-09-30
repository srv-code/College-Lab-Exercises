/*
create table emp_1
(
	empno number(3),
	ename varchar2(10),
	sal number(5),
	bdate date
);
*/

/*
insert into emp_1 values (1, 'Abc', 5000, to_date('20-01-2001', 'DD-MM-YYYY'));
insert into emp_1 values (2, 'Cde', 10000, to_date('22-12-2001', 'DD-MM-YYYY'));
insert into emp_1 values (3, 'Fgh', 2000, to_date('20-12-2001', 'DD-MM-YYYY'));
insert into emp_1 values (4, 'Ijk', 4000, to_date('20-10-2001', 'DD-MM-YYYY'));
insert into emp_1 values (5, 'Lmn', 2500, to_date('19-09-2001', 'DD-MM-YYYY'));
-- insert into emp_1(empno, sal) values (4, 1000);
-- insert into emp_1 values (&emp_no, '&ename', &sal, to_date('&bdate', 'DD-MM-YYYY'));
*/

/*
update emp_1 
	set sal = sal / 10
	where empno between 2 and 3;
*/


-- delete from emp_1; 
-- delete from emp_1 
--	where empno >= 2;
-- delete from emp_1 where dno in 
--	(select dno from dept_1 where dname='research');
-- rollback;

-- select * from emp_1;
-- 8.2 Write a PL/SQL block to accept employee number and display Employee Name, salary of employees in the format – ‘RAVI draws 32000/- as salary’.

set serveroutput on;

declare
	eno			emp.empno%type := &empno;
	nm			emp.ename%type;
	salary		emp.sal%type;
begin
	select upper(ename), sal into nm, salary from emp where empno = eno;
	dbms_output.put_line(nm || ' draws ' || salary || '/- as salary.');
end;
/

/* Output:
	Enter value for empno: 101
	old   2:        eno                     emp.empno%type := &empno;
	new   2:        eno                     emp.empno%type := 101;
	RAVI draws 32000/- as salary.
*/
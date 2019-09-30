-- 9.1 Write a cursor to display ENAME and SAL of all employees drawing salary more than 30000/-. 

set serveroutput on;

declare 
	cursor cur_emp is 
		select ename, sal
			from emp 
				where sal > 30000;
begin
	for v_cur_rec in cur_emp 
	loop 
		dbms_output.put_line('Empno:  ' || v_cur_rec.ename || ', Salary:  ' || v_cur_rec.sal);
	end loop;
end;
/

/* Output:
	Empno:  Ravi, Salary:  32000
	Empno:  Mahesh, Salary:  35000
	Empno:  Raghu, Salary:  45000
	Empno:  , Salary:  60000
	Empno:  sdkjsd, Salary:  32000
	Empno:  Raviram, Salary:  32000

	PL/SQL procedure successfully completed.
*/	
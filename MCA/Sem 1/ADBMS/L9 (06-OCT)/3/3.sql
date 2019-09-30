-- 9.3 Write a parameterized cursor to find employee with the given job and dept no.

set serveroutput on;

declare 
	cursor cur_emp(v_deptno varchar2, v_job varchar2) is 
		select empno, ename, sal, job, deptno 
			from emp 
				where deptno=v_deptno and job=v_job;
	v_job		emp.job%type := '&job';
	v_deptno	emp.deptno%type := '&deptno';
begin
	for v_cur_rec in cur_emp(v_deptno, v_job)
	loop 
		dbms_output.put_line('Empno: ' || v_cur_rec.empno 
								|| ', Ename: ' || v_cur_rec.ename 
									|| ', Salary: ' || v_cur_rec.sal
										|| ', Job: ' || v_cur_rec.job 
											|| ', Dept No: ' || v_cur_rec.deptno);
	end loop;
end;
/

/* Output:
	Enter value for job: CLRK
	old   6:        v_job           emp.job%type := '&job';
	new   6:        v_job           emp.job%type := 'CLRK';
	Enter value for deptno: D1
	old   7:        v_deptno        emp.deptno%type := '&deptno';
	new   7:        v_deptno        emp.deptno%type := 'D1';
	Empno: 102, Ename: Raviraj, Salary: 24000, Job: CLRK, Dept No: D1
	Empno: 120, Ename: sdkjsd, Salary: 32000, Job: CLRK, Dept No: D1
	Empno: 121, Ename: Raviram, Salary: 32000, Job: CLRK, Dept No: D1

	PL/SQL procedure successfully completed.
*/
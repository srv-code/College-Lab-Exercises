set serveroutput on;

declare 
	cursor cur_emp(pno emp.prj_id%type) is 
		select ename, sal, dname from emp, dept 
			where emp.deptno=dept.dno and prj_id=pno and rownum<=2
				order by sal;
	pno		emp.prj_id%type:='&prj_id';
begin 
	for cur_rec in cur_emp(pno)
	loop
		dbms_output.put_line('Ename: ' || cur_rec.ename || ', Salary: ' || cur_rec.sal || ', Dept Name: ' || cur_rec.dname);
	end loop;
end;
/
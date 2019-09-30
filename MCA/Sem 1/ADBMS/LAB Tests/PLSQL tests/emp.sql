/* Find the area of the circle */
set serveroutput on
declare 
	v_ename varchar2(20);
	v_job emp.job%type;
	v_deptno emp.deptno%type;
	v_empno emp.empno%type;
begin
	v_empno := &v_empno;
	select ename, job, deptno into v_ename, v_job, v_deptno
		from emp 
		where empno=v_empno;
		
	dbms_output.put_line('ename=' || v_ename);
	dbms_output.put_line('job=' || v_job);
	dbms_output.put_line('deptno=' || v_deptno);
end;
/
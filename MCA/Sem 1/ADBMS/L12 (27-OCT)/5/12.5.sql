-- 12.5 Write functions to find department name and number of projects it is handling. Display this information in the calling PL/SQL block. 

create or replace function fn_find_dept_name(v_dno in dept.dno%type) return dept.dname%type is 
	v_dname		dept.dname%type;
begin 
	select dname into v_dname from dept where dno = v_dno;
	return(v_dname);
end; 
/
 
create or replace function fn_find_project_count(v_dno in dept.dno%type) return number is
	v_prj_count	number(3);
begin 
	select count(*) into v_prj_count from proj where dno=v_dno;
	return(v_prj_count);
end;
/

set serveroutput on;
declare 
	v_dno	dept.dno%type := '&dept_number';
begin
	dbms_output.put_line('Dept name for dept no ' || v_dno || ' is ' || fn_find_dept_name(v_dno) || '.');
	dbms_output.put_line('Project count under dept no ' || v_dno || ' is ' || fn_find_project_count(v_dno) || '.');
end;
/


/* Output: 
	Enter value for dept_number: D2
	old   2:        v_dno   dept.dno%type := '&dept_number';
	new   2:        v_dno   dept.dno%type := 'D2';
	Dept name for dept no D2 is Reasearch.
	Project count under dept no D2 is 1.

	PL/SQL procedure successfully completed.
*/
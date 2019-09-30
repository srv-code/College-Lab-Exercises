/*
create or replace procedure display_salary(empid IN char, sal OUT number) is 
	v_sal 	number(10,2);
begin
	select sal into v_sal from emp where empno=empid;
	if v_sal > 15000 then 
		dbms_output.put_line('Your salary ' || v_sal || ' is > 15,000.');
	else 
		dbms_output.put_line('Your salary ' || v_sal || ' is <= 15,000.');
	end if;
	sal := v_sal;
	
	exception 
		when no_data_found then 
			dbms_output.put_line('No such empno exists!');
end display_salary;
/
*/

set serveroutput on;
declare 
	v_empno	emp.empno%type := &empno;
	v_sal	emp.sal%type;
begin 
	display_salary(v_empno, v_sal);
	dbms_output.put_line('v_empno=' || v_empno || ', v_sal=' || to_char(v_sal));
end;
/

/* For running in SQL Prompt:
	var v_sal number;
	exec display_salary(101, :v_sal);
	print v_sal;
*/
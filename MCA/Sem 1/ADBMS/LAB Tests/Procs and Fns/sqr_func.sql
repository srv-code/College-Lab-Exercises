/*
create or replace function sqr_func(num1 IN number) 
	return number is 
result	number(3);
begin
	result := num1 * num1;
	return result;
end;
/
*/

set serveroutput on;
declare 
	a number(3);
begin 
	a:=&a;
	dbms_output.put_line('Sq: ' || sqr_func(a));
end;
/

/* From SQL Prompt: 
	SQL> select sqr_func(5) from dual;
	SQR_FUNC(5)
	-----------
			 25
*/
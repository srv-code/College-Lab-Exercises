create or replace procedure squareNum2(num1 IN number, num2 OUT number) is 
	result number(3);
begin 
	result := num1 * num1;
	num2 := result;
end;
/

/*
set serveroutput on;
declare 
	a number(3);
	b number(3);
begin 
	a:=&a;
	squareNum2(a, b);
	dbms_output.put_line('Sq(' || a || ')=' || b);
end;
/
*/
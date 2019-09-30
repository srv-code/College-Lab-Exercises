create or replace procedure squareNum(x IN OUT number) is 
begin 
	x := x*x;
end;
/

/*
set serveroutput on;
declare 
	a number(3);
begin 
	a:=&a;
	squareNum(a);
	dbms_output.put_line('Sq: ' || a);
end;
/
*/
create or replace package Calculate1 is 
	function sqr1(num in number) return number;
	procedure cube1(num in number, res out number);
end;
/

create or replace package body Calculate1 is 
	function sqr1(num in number) return number is
	begin 
		return (num*num);
	end;
	
	procedure cube1(num in number, res out number) is
	begin 
		res := (num*num*num);
	end;
end;
/


set serveroutput on;
declare 
	num	number(5);
begin
	dbms_output.put_line(Calculate1.sqr1(5));
	Calculate1.cube1(5, num);
	dbms_output.put_line(num);
end;
/

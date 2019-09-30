-- 12.3 Write a function to calculate square of a number and return calculated value to the calling PL/SQL block.

create or replace function fn_sqr(num in number) return number as 
begin 
	return (num*num);
end;
/

set serveroutput on;
declare 
	num		number(3) := &number;
begin 
	dbms_output.put_line('square of ' || num || ' = ' || fn_sqr(num));
end;
/

/* Output: 
	Enter value for number: 23
	old   2:        num             number(3) := &number;
	new   2:        num             number(3) := 23;
	square of 23 = 529

	PL/SQL procedure successfully completed.
*/
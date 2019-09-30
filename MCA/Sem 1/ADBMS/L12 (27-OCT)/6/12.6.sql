-- 12.6 Write a package containing procedure to calculate area of circle, perimeter and a function to find factorial of a number. 

create or replace package my_pack is 
	procedure circle_area(rad in number, res out number);
	procedure circle_perimeter(rad in number, res out number);	
	function factorial(num in number) return number;
end;
/ 

create or replace package body my_pack is 
	procedure circle_area(rad in number, res out number) is 
		PI	number(3, 2) := 3.14;
	begin
		res := (PI * rad * rad);
	end;
	
	procedure circle_perimeter(rad in number, res out number) is 
		PI	number(3, 2) := 3.14;
	begin
		res := (2*PI*rad);
	end;
	
	function factorial(num in number) return number is 
		res		number(5) := 1;
		no		number(3) := num;
	begin 
		while no > 0
		loop
			res := res * no;
			no:= no - 1;
		end loop;		
		return res;
	end;
end;
/ 

set serveroutput on;
declare 
	num			number(5, 2) := &number;
	rad			number(5, 2) := &radius;
	area		number(7, 2);
	perimeter	number(7, 2);
begin
	my_pack.circle_area(rad, area);
	dbms_output.put_line('Area of circle with radius ' || rad || ': ' || area);
	
	my_pack.circle_perimeter(rad, perimeter);
	dbms_output.put_line('Perimeter of circle with radius ' || rad || ': ' || perimeter);
	
	dbms_output.put_line('Factorial of ' || num || ': ' || my_pack.factorial(num));
end;
/

/* Output: 
	Package created.

	Package body created.

	Enter value for number: 5
	old   2:        num                     number(5, 2) := &number;
	new   2:        num                     number(5, 2) := 5;
	Enter value for radius: 3
	old   3:        rad                     number(5, 2) := &radius;
	new   3:        rad                     number(5, 2) := 3;
	Area of circle with radius 3: 28.26
	Perimeter of circle with radius 3: 18.84
	Factorial of 5: 120

	PL/SQL procedure successfully completed.
*/
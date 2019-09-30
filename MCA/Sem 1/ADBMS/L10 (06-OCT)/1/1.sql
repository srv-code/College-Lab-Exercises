-- 10.1 Write a program to demonstrate predefined exceptions

set serveroutput on;

declare
	v_num	number(5,2) := &numerator;
	v_den	number(5,2) := &denominator;
begin
	dbms_output.put_line('Numerator: ' || v_num);
	dbms_output.put_line('Denominator: ' || v_den);
	dbms_output.put_line('Division result: ' || (v_num/v_den));
	
	exception 
		when zero_divide then
			dbms_output.put_line('Error: Division by a zero denominator');
end;
/

/* Output: 
Case- Failure:
	Enter value for numerator: 2
	old   2:        v_num   number(5,2) := &numerator;
	new   2:        v_num   number(5,2) := 2;
	Enter value for denominator: 0
	old   3:        v_den   number(5,2) := &denominator;
	new   3:        v_den   number(5,2) := 0;
	Numerator: 2
	Denominator: 0
	Error: Division by a zero denominator

	PL/SQL procedure successfully completed.
	
Case- Successful:
	Enter value for numerator: 8
	old   2:        v_num   number(5,2) := &numerator;
	new   2:        v_num   number(5,2) := 8;
	Enter value for denominator: 4
	old   3:        v_den   number(5,2) := &denominator;
	new   3:        v_den   number(5,2) := 4;
	Numerator: 8
	Denominator: 4
	Division result: 2

	PL/SQL procedure successfully completed.
*/
-- 7.1 Write a PL/SQL block to find the sum of the digits of a given number.

set serveroutput on;

declare 
	n	number(4) := &number;
	s	number(4) := 0;
begin
	dbms_output.put('Sum of digits of number ' || n || ': ');
	
	while n > 0 
		loop
			s := s + mod(n, 10);
			n := n / 10;
		end loop;
		
	dbms_output.put_line(s);
end;
/

/* Output:
	Enter value for number: 122
	old   2:        n       number(4) := &number;
	new   2:        n       number(4) := 122;
	Sum of digits of number 122: 5

	PL/SQL procedure successfully completed.
*/
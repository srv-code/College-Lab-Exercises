-- 7.2 Write a PL/SQL block to check whether the given number is Armstrong or not.

set serveroutput on;

declare 
	n	number(4) := &number;
	q	number(4) := n;
	s 	number(4) := 0;
begin
	while q > 0
		loop
			s := s + power(mod(q, 10), 3);
			q := trunc(q / 10);
		end loop;
		
		if s = n then
			dbms_output.put_line('Number ' || n || ' is an armstrong number.');
		else
			dbms_output.put_line('Number ' || n || ' is not an armstrong number.');
		end if;
end;
/

/* Output:
	Case 1:
		Enter value for number: 125
		old   2:        n       number(4) := &number;
		new   2:        n       number(4) := 125;
		Number 125 is not an armstrong number.

		PL/SQL procedure successfully completed.
		
		
	Case 2:
		Enter value for number: 371
		old   2:        n       number(4) := &number;
		new   2:        n       number(4) := 371;
		Number 371 is an armstrong number.

		PL/SQL procedure successfully completed.
*/
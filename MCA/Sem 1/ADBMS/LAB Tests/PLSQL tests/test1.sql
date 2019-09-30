set serveroutput on

declare 
	a	number(4) := 281;
begin 
	dbms_output.put_line('a=' || a);
	while a > 0 
		loop
			a := trunc(a / 10);
			dbms_output.put_line('a=' || a);
		end loop;
end;
/
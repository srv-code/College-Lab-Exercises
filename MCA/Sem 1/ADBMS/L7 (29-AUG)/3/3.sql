-- 7.3 Write a PL/SQL block to apply string functions on a given string.

set serveroutput on;

declare 
	str	varchar(20) := '&string';
begin
	dbms_output.put_line('Length:  ' || length(str));
	dbms_output.put_line('Substring(2, 3):  ' || substr(str, 2, 3));
	dbms_output.put_line('Initcap:  ' || initcap(str));
	dbms_output.put_line('Instring(e):  ' || instr(str, 'e'));
	dbms_output.put_line('Lowercase:  ' || lower(str));
	dbms_output.put_line('Uppercase:  ' || upper(str));
end;
/

/* Output: 
	Enter value for string: abcdef
	old   2:        str     varchar(20) := '&string';
	new   2:        str     varchar(20) := 'abcdef';
	Length:  6
	Substring(2, 3):  bcd
	Initcap:  Abcdef
	Instring(e):  5
	Lowercase:  abcdef
	Uppercase:  ABCDEF

	PL/SQL procedure successfully completed.
*/
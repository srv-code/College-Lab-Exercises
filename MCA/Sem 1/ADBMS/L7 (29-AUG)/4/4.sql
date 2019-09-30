-- 7.4 Write a PL/SQL block to check an input string is palindrome or not palindrome. 

set serveroutput on;

declare 
	str		varchar(20) := '&string';
	i		number(3);
	j		number(3);
	n		number(3);
	sz		number(3);
begin
	i := 1;
	sz := length(str);
	j := sz;
	n := trunc(sz / 2);
	
	while i <= n
		loop
			exit when (substr(str, i, 1) != substr(str, j, 1));
			i := i + 1;
			j := j - 1;
		end loop;
		
	if (i = n+1) then
		dbms_output.put_line('String "' || str || '" is palindrome.');
	else 
		dbms_output.put_line('String "' || str || '" is not palindrome.');
	end if;
end;
/

/* Output:
	Case1:
		Enter value for string: madam
		old   2:        str             varchar(20) := '&string';
		new   2:        str             varchar(20) := 'madam';
		String "madam" is palindrome.

		PL/SQL procedure successfully completed.

	Case 2:
		Enter value for string: adjksd
		old   2:        str             varchar(20) := '&string';
		new   2:        str             varchar(20) := 'adjksd';
		a=a, b=d, i=, j=6, n=3
		String "adjksd" is not palindrome.

		PL/SQL procedure successfully completed.
*/
/*
	8.4 Write a PL/SQL block to calculate the area of a circle for a value of radius varying from 3 to 7. 
	Store the Radius and the corresponding values of calculated Area in an empty table named CIRCLE, consisting of two columns radius & area
*/

declare
	rad		circle.radius%type := 3;
begin
	while rad <= 7
		loop
			insert into circle values (rad, 3.14 * rad * rad);
			rad := rad + 1;
		end loop;
	commit;
end;
/

/* Output:
		RADIUS       AREA
	---------- ----------
			 3      28.26
			 4      50.24
			 5       78.5
			 6     113.04
			 7     153.86
*/
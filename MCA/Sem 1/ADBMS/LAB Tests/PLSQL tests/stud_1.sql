-- Write a PL/SQL block to accept regno from user and process his average marks and grade. Update the average marks and grade of that student in the table.

set serveroutput on
declare 
	v_regno stud.regno%type;
begin
	v_regno := &v_regno;
	
	update stud 
		set	avg_mark = (mark1 + mark2) / 2
		where regno = v_regno;
	commit;
	
	-- dbms_output.put_line('updated successfully');
end;
/
create or replace package stud_res is 
	function stud_tot(m1 in number, m2 in number, m3 in number) return number;
	procedure stud_avg(m1 in number, m2 in number, m3 in number, mavg out number);
end;
/

create or replace package body stud_res is 
	function stud_tot(m1 in number, m2 in number, m3 in number) return number is 
	begin 
		return (m1+m2+m3);
	end;
	
	procedure stud_avg(m1 in number, m2 in number, m3 in number, mavg out number) is 
	begin 
		mavg := (m1+m2+m3)/3;
	end;	
end;
/

set serveroutput on;
declare 
	m1		number(4, 2) := &marks1;
	m2		number(4, 2) := &marks2;
	m3		number(4, 2) := &marks3;
	mavg	number(4, 2);
begin 
	dbms_output.put_line('Total marks: ' || stud_res.stud_tot(m1, m2, m3));
	stud_res.stud_avg(m1, m2, m3, mavg);
	dbms_output.put_line('Average marks: ' || mavg);
end;
/
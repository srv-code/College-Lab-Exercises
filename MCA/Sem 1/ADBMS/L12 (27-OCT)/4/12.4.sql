-- 12.4 Write two functions to calculate age and service experience of all employees and return these values to calling PL/SQL block and display. 

create or replace function fn_calc_total_ages return number as 
	ages_sum	number(5);	
begin 
	select sum(extract(year from sysdate)-extract(year from date_birth)) into ages_sum from emp;
	return ages_sum;
end;
/ 

create or replace function fn_calc_total_experience return number as 
	exp_sum		number(5);
begin 
	select sum(extract(year from sysdate)-extract(year from date_of_join)) into exp_sum from emp;
	return exp_sum;
end;
/ 

set serveroutput on;
declare 
	n	number(3);
begin 
	dbms_output.put_line('Total ages of all employees: ' || fn_calc_total_ages || ' years');
	dbms_output.put_line('Total experiences of all employees: ' || fn_calc_total_experience || ' years');
end;
/

/* Output: 
	Total ages of all employees: 368 years
	Total experiences of all employees: 164 years

	PL/SQL procedure successfully completed.
*/
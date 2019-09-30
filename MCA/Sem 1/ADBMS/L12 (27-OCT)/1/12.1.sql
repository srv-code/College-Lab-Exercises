-- 12.1 Write a procedure to calculate simple interest, taking principle, rate and year as inputs.

create or replace procedure proc_calc_simple_interest(principle in number, rate in number, year in number, interest out number) as
begin 
	interest := (principle*year*rate) / 100;
end;
/ 

/* Output:	
	SQL> var interest number;
	
	SQL> exec proc_calc_simple_interest(1500, 5.6, 3, :interest);
	PL/SQL procedure successfully completed.

	SQL> print interest;
	  INTEREST
	----------
		   252
*/
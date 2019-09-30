-- 10.2 Write a PL/SQL block to accept, Principle, Interest rate and duration (in years) to calculate Interest to be paid. Handle the exceptions if Principle <=1000, interest rate <5, year <1 and display proper error message for each. 

set serveroutput on;

declare 
	v_principle_amount		number(7,2) := &principle_amount;
	v_interest_rate			number(4,2) := &interest_rate;
	v_duration				number(5,2) := &duration;
	v_interest_amount		number(7,2);
	
	exc_less_principle		exception;
	exc_less_interest_rate	exception;
	exc_less_duration		exception;
begin 
	if v_principle_amount <= 1000 then
		raise exc_less_principle;
	end if;
	
	if v_interest_rate < 5 then
		raise exc_less_interest_rate;
	end if;
	
	if v_duration < 1 then
		raise exc_less_duration;
	end if;
	
	v_interest_amount := v_principle_amount * v_duration * v_interest_rate / 100;
	
	dbms_output.put_line('Simple interest amount: ' || v_interest_amount);
	
	
	exception 
		when exc_less_principle then
			dbms_output.put_line('Error: Principle amount cannot be less than or equal to 1000.');
			
		when exc_less_interest_rate then
			dbms_output.put_line('Error: Rate of interest cannot be less than 5.');
			
		when exc_less_duration then
			dbms_output.put_line('Error: Duration cannot be less than 1 year.');
end;
/

/* Output: 
	Case- Interest rate lesser than 5: 
		Enter value for principle_amount: 2000
		old   2:        v_principle_amount              number(7,2) := &principle_amount;
		new   2:        v_principle_amount              number(7,2) := 2000;
		Enter value for interest_rate: 2
		old   3:        v_interest_rate                 number(4,2) := &interest_rate;
		new   3:        v_interest_rate                 number(4,2) := 2;
		Enter value for duration: 0.3
		old   4:        v_duration                              number(5,2) := &duration;
		new   4:        v_duration                              number(5,2) := 0.3;
		Error: Rate of interest cannot be less than 5.

		PL/SQL procedure successfully completed.
		
	Case- Principle amount lesser than or equal to 1000:
		Enter value for principle_amount: 900
		old   2:        v_principle_amount              number(7,2) := &principle_amount;
		new   2:        v_principle_amount              number(7,2) := 900;
		Enter value for interest_rate: 5
		old   3:        v_interest_rate                 number(4,2) := &interest_rate;
		new   3:        v_interest_rate                 number(4,2) := 5;
		Enter value for duration: 4
		old   4:        v_duration                              number(5,2) := &duration;
		new   4:        v_duration                              number(5,2) := 4;
		Error: Principle amount cannot be less than or equal to 1000.

		PL/SQL procedure successfully completed.
		
	Case- Duration in years lesser than 1:
		Enter value for principle_amount: 2000
		old   2:        v_principle_amount              number(7,2) := &principle_amount;
		new   2:        v_principle_amount              number(7,2) := 2000;
		Enter value for interest_rate: 6
		old   3:        v_interest_rate                 number(4,2) := &interest_rate;
		new   3:        v_interest_rate                 number(4,2) := 6;
		Enter value for duration: 0.3
		old   4:        v_duration                              number(5,2) := &duration;
		new   4:        v_duration                              number(5,2) := 0.3;
		Error: Duration cannot be less than 1 year.

		PL/SQL procedure successfully completed.
		
	Case- Successful run:
		Enter value for principle_amount: 2000
		old   2:        v_principle_amount              number(7,2) := &principle_amount;
		new   2:        v_principle_amount              number(7,2) := 2000;
		Enter value for interest_rate: 6
		old   3:        v_interest_rate                 number(4,2) := &interest_rate;
		new   3:        v_interest_rate                 number(4,2) := 6;
		Enter value for duration: 2
		old   4:        v_duration                              number(5,2) := &duration;
		new   4:        v_duration                              number(5,2) := 2;
		Simple interest amount: 240

		PL/SQL procedure successfully completed.
*/
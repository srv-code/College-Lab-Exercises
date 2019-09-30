---- ORACLE In-built named error msgs

set serveroutput on;

declare 
	v_cointosses		integer := &v_cointosses;
	v_head				integer := &v_head;
	v_prob				number;
begin 
	v_prob := v_head / v_cointosses;
	dbms_output.put_line('Probability is: ' || v_prob);
	
	exception 
		when zero_divide then  -- Named exception
			dbms_output.put_line('No of coin tosses can''t be zero.');
			dbms_output.put_line('Calling square user defined function ' || sqr_fun(3)); -- calling user defined function: sqr_fun
end;
/
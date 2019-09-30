/*
	12.2 Write a procedure to take SAL of given Employee as input and calculate HRA, PF,
	DA, GROSS, TAX and NETSAL and return them to calling PL/SQL block(take
	EMPNO as keyboard input to get SAL).
*/

create or replace procedure proc_calc_sal_slip(	sal in number, 
												hra out number, 
												pf out number, 
												da out number, 
												gross out number, 
												tax out number, 
												netsal out number) as 
begin 
	hra    := sal * 0.15;
	pf     := sal * 0.2;
	da     := sal * 0.25;
	gross  := sal + hra + pf + da;
	tax    := sal * 0.15;
	netsal := gross - tax;
end;
/

set serveroutput on;
declare 
	v_empno			emp.empno%type := &empno;
	v_sal			number(7, 2);
	v_hra			number(7, 2);
	v_pf			number(7, 2);
	v_da			number(7, 2);
	v_gross			number(7, 2);
	v_tax			number(7, 2);
	v_netsal		number(7, 2);
begin 
	select sal into v_sal from emp where empno = v_empno;
	proc_calc_sal_slip(v_sal, v_hra, v_pf, v_da, v_gross, v_tax, v_netsal);
	
	dbms_output.put_line('Salary slip:');
	dbms_output.put_line('Basic salary: Rs. ' || v_sal);
	dbms_output.put_line('House rent allowance: Rs. ' || v_hra);
	dbms_output.put_line('Provident fund: Rs. ' || v_pf);
	dbms_output.put_line('Dearness allowance: Rs. ' || v_da);
	dbms_output.put_line('Gross: Rs. ' || v_gross);
	dbms_output.put_line('Income tax: Rs. ' || v_tax);
	dbms_output.put_line('Net salary: Rs. ' || v_netsal);
end;
/

/* Output: 
	Enter value for empno: 101
	old   2:        v_empno                 emp.empno%type := &empno;
	new   2:        v_empno                 emp.empno%type := 101;
	Salary slip:
	Basic salary: Rs. 32000
	House rent allowance: Rs. 4800
	Provident fund: Rs. 6400
	Dearness allowance: Rs. 8000
	Gross: Rs. 51200
	Income tax: Rs. 4800
	Net salary: Rs. 46400

	PL/SQL procedure successfully completed.
*/
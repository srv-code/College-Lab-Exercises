/*
	8.3 Write a PL/SQL block for inserting rows into EMPSAL with the following calculations:
		HRA=50% of Basic
		DA=20% of Basic
		PF=12% of Basic.
	Insert the empno, empname, basic salary, HRA, DA, Gross Salary, PF, Net Salary in the table EMPSAL.
*/

set serveroutput on;

declare
	eno			empsal.empno%type := &empno;
	nm			empsal.empname%type := '&ename';
	bsal		empsal.basic_salary%type := &basic_salary;
	hra			empsal.hra%type;
	da			empsal.da%type;
	gsal		empsal.gross_salary%type;
	pf			empsal.pf%type;
	nsal		empsal.net_salary%type;
begin
	hra := 0.5 * bsal;
	da := 0.2 * bsal;
	pf := 0.12 * bsal;
	gsal := bsal + hra + da;
	nsal := gsal - pf;
	
	insert into empsal values (eno, nm, bsal, hra, da, gsal, pf, nsal);
	commit;
end;
/

/* Output:
	Enter value for empno: 1
	old   2:        eno                     empsal.empno%type := &empno;
	new   2:        eno                     empsal.empno%type := 100;
	Enter value for ename: aaaaaa
	old   3:        nm                      empsal.empname%type := '&ename';
	new   3:        nm                      empsal.empname%type := 'Arman';
	Enter value for basic_salary: 1200
	old   4:        bsal            empsal.basic_salary%type := &basic_salary;
	new   4:        bsal            empsal.basic_salary%type := 1200;

	PL/SQL procedure successfully completed.
*/
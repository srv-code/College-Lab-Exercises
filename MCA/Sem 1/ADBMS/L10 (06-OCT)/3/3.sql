/*
	10.3 Write a PL/SQL block to accept employee number from user and display employee details such as Empno, Name, and Sal. Handle the exception raised –
		(i)  If user entered a non–existing employee number.
		(ii) If the salary more than 25000/-
	If employee exists and salary is less than 25000/- then update that salary to 25000/-
*/

set serveroutput on;

declare 
	v_empno			emp.empno%type := &empno;
	v_ename			emp.ename%type;
	v_sal			emp.sal%type;
	higher_salary		exception;
begin 
	select ename, sal into v_ename, v_sal from emp where empno = v_empno;
	
	dbms_output.put_line('Employee details:');
	dbms_output.put_line('Employee No: ' || v_empno);
	dbms_output.put_line('Name: ' || v_ename);
	dbms_output.put_line('Salary: ' || v_sal);
	
	if v_sal > 25000 then 
		raise higher_salary;
	elsif v_sal < 25000 then 
		update emp 
			set sal = 25000
			where empno = v_empno;
		commit;
		dbms_output.put_line('Salary of ' || v_ename || ' updated to 25000.');
	end if; 
	
	
	exception 
		when no_data_found then 
			dbms_output.put_line('Error: No such employee number exists!');
			
		when higher_salary then 
			dbms_output.put_line('Error: Higher salary than 25000 found!');
end;
/

/* Output:
	Case- Higher salary than 25000: 
		Enter value for empno: 101
		old   2:        v_empno                 emp.empno%type := &empno;
		new   2:        v_empno                 emp.empno%type := 101;
		Employee details:
		Employee No: 101
		Name: Ravi
		Salary: 32000
		Error: Higher salary than 25000 found!

		PL/SQL procedure successfully completed.
		
	Case- Non-existing employee number:
		Enter value for empno: 129
		old   2:        v_empno                 emp.empno%type := &empno;
		new   2:        v_empno                 emp.empno%type := 129;
		Error: No such employee number exists!

		PL/SQL procedure successfully completed.
		
	Case- Successful run: 
		Enter value for empno: 102
		old   2:        v_empno                 emp.empno%type := &empno;
		new   2:        v_empno                 emp.empno%type := 102;
		Employee details:
		Employee No: 102
		Name: Raviraj
		Salary: 24000
		Salary of Raviraj updated to 25000.

		PL/SQL procedure successfully completed.
*/
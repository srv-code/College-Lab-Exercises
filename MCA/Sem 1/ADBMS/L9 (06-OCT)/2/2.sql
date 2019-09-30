-- 9.2 Write a cursor to display the list of employees and total salary department wise.

set serveroutput on;

declare 
	cursor cur_enames is
		select ename from emp;
	cursor cur_tot_sal_dept_wise is 
		select deptno, sum(sal) as total_sal
			from emp 
				group by deptno	
					order by 2;
begin 
	-- select ename from emp;
	dbms_output.put_line('List of employees:');
	for v_cur_rec in cur_enames
	loop 
		dbms_output.put_line(v_cur_rec.ename);
	end loop;
	
	-- select deptno, sum(sal) as total_sal from emp group by deptno order by 1;
	dbms_output.put_line('Total salary department wise:');
	for v_cur_rec in cur_tot_sal_dept_wise
	loop 
		dbms_output.put_line('Dept No: ' || v_cur_rec.deptno || ', Total salary: ' || v_cur_rec.total_sal);
	end loop;
end;
/

/* Output:
	List of employees:
	Ravi
	Mahesh
	Raviraj
	Raghu
	Manu
	sdkjsd
	Raviram
	Total salary department wise:
	Dept No: D1, Total salary: 120000
	Dept No: D3, Total salary: 140000
	Dept No: D4, Total salary:

	PL/SQL procedure successfully completed.
*/
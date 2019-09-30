-- L8 8.1 Write a PL/SQL block to insert row into EMP table.

declare
	empno		emp.empno%type := &empno;
	ename		emp.ename%type := '&ename';
	job			emp.job%type := '&job';
	mgr_id		emp.mgr_id%type := &mgr_id;
	dob			emp.date_birth%type := to_date('&date_birth', 'DD-MM-YYYY');
	sal			emp.sal%type := &sal;
	comm		emp.comm%type := &comm;
	deptno		emp.deptno%type := '&deptno';
	doj			emp.date_of_join%type := to_date('&date_of_join', 'DD-MM-YYYY');
	prj_id		emp.prj_id%type := '&prj_id';
begin
	insert into emp values (empno, ename, job, mgr_id, dob, sal, comm, deptno, doj, prj_id);
	commit;
end;
/

/* Output:
	Enter value for empno: 121
	old   2:        empno           emp.empno%type := &empno;
	new   2:        empno           emp.empno%type := 121;
	Enter value for ename: Raviram
	old   3:        ename           emp.ename%type := '&ename';
	new   3:        ename           emp.ename%type := 'Raviram';
	Enter value for job: CLRK
	old   4:        job                     emp.job%type := '&job';
	new   4:        job                     emp.job%type := 'CLRK';
	Enter value for mgr_id: 101
	old   5:        mgr_id          emp.mgr_id%type := &mgr_id;
	new   5:        mgr_id          emp.mgr_id%type := 101;
	Enter value for date_birth: 12-01-1980
	old   6:        dob                     emp.date_birth%type := to_date('&date_birth', 'DD-MM-YYYY');
	new   6:        dob                     emp.date_birth%type := to_date('12-01-1980', 'DD-MM-YYYY');
	Enter value for sal: 32000
	old   7:        sal                     emp.sal%type := &sal;
	new   7:        sal                     emp.sal%type := 32000;
	Enter value for comm: 200
	old   8:        comm            emp.comm%type := &comm;
	new   8:        comm            emp.comm%type := 200;
	Enter value for deptno: D1
	old   9:        deptno          emp.deptno%type := '&deptno';
	new   9:        deptno          emp.deptno%type := 'D1';
	Enter value for date_of_join: 12-01-2000
	old  10:        doj                     emp.date_of_join%type := to_date('&date_of_join', 'DD-MM-YYYY');
	new  10:        doj                     emp.date_of_join%type := to_date('12-01-2000', 'DD-MM-YYYY');
	Enter value for prj_id: P1
	old  11:        prj_id          emp.prj_id%type := '&prj_id';
	new  11:        prj_id          emp.prj_id%type := 'P1';

	PL/SQL procedure successfully completed.
*/
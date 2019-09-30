/*
	11.5 Write a PL/SQL block trigger to carry out the following action: on deleting a
	deptno from dept table, all the records with that deptno has to be deleted from the
	emp table.
*/

create or replace trigger tgr_deptno_on_delete_cascade 
	after delete on dept1 for each row 
begin 
	delete from emp1 
		where deptno = :old.dno;
end;
/

/* Output: 
	SQL> select count(*) from emp where deptno='D4';
	  COUNT(*)
	----------
			 3

	SQL> select count(*) from dept where dno='D4';
	  COUNT(*)
	----------
			 1

	SQL> delete from dept where dno='D4';
	1 row deleted.

	SQL> select count(*) from dept where dno='D4';
	  COUNT(*)
	----------
			 0

	SQL> select count(*) from emp where deptno='D4';
	  COUNT(*)
	----------
			 0
*/
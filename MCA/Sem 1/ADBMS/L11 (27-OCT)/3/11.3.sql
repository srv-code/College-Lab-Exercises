/*
	11.3 Write a PL/SQL trigger to fire when there is an insert /update/deletes operation on
	EMP table; record the information in AUDIT_EMP table which has same structure
	as that of EMP along with a new column OPERATION (stores
	UPDATE/INSERT/DELETE depending on operation being done.) 
*/

create table audit_emp as (select * from emp where 1=2);
alter table audit_emp add operation varchar(6) not null;

create or replace trigger tgr_audit_emp
	after insert or update or delete on emp for each row 
begin 
	if inserting then 
		insert into audit_emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id, operation) values (:new.empno, :new.ename, :new.job, :new.mgr_id, :new.date_birth, :new.sal, :new.comm, :new.deptno, :new.date_of_join, :new.prj_id, 'INSERT');
	elsif updating then 
		insert into audit_emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id, operation) values (:old.empno, :old.ename, :old.job, :old.mgr_id, :old.date_birth, :old.sal, :old.comm, :old.deptno, :old.date_of_join, :old.prj_id, 'UPDATE');
	else 
		insert into audit_emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id, operation) values (:old.empno, :old.ename, :old.job, :old.mgr_id, :old.date_birth, :old.sal, :old.comm, :old.deptno, :old.date_of_join, :old.prj_id, 'DELETE');
	end if;
end;
/

/* Output:
Case- Inserting into emp table: 
	SQL> insert into emp values (155, 'Sam', 'CLRK', 101, to_date('30-11-1883', 'dd-mm-yyyy'), 32000, 1500, 'D2', to_date('11-2-2000', 'dd-mm-yyyy'), 'P1');
	1 row created.

	SQL> select * from audit_emp;
		 EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I OPERATION
	---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- ----- ---------
		   155 Sam        CLRK             101 30-NOV-83      32000       1500 D2  11-FEB-00 P1    INSERT
		   
Case- Updating emp table:
	SQL> update emp set job='MGR' where empno=155;
	1 row updated.

	SQL> select * from audit_emp;
		 EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I OPERATION
	---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- ----- ---------
		   155 Sam        CLRK             101 30-NOV-83      32000       1500 D2  11-FEB-00 P1    INSERT
		   155 Sam        CLRK             101 30-NOV-83      32000       1500 D2  11-FEB-00 P1    UPDATE
		   
Case- Deleting from emp table:
	SQL> delete from emp where empno=155;
	1 row deleted.

	SQL> select * from audit_emp;
		 EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I OPERAT
	---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- ----- ------
		   155 Sam        CLRK             101 30-NOV-83      32000       1500 D2  11-FEB-00 P1    INSERT
		   155 Sam        CLRK             101 30-NOV-83      32000       1500 D2  11-FEB-00 P1    UPDATE
		   155 Sam        MGR              101 30-NOV-83      32000       1500 D2  11-FEB-00 P1    DELETE
*/
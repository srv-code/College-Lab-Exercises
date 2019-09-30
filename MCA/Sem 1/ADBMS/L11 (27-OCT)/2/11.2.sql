/* 
	11.2 Write a PL/SQL trigger to fire when there is an updation of salary of any employee
	and record the Empno, Dept. Name and Old Salary, date on which salary is
	modified and user who modified information in the table SAL_MOD (Empno,
	Dname, Old_Sal, Mod_Date, Modifier).
*/

create table sal_mod
(
	empno		number(4) references emp(empno),
	dname 		varchar2(10),
	old_sal		number(7,2),	
	mod_date	date,	
	modifier	varchar2(25)
);

create or replace trigger tgr_update_sal
	after update of sal on emp for each row
declare 
	v_dname		dept.dname%type;
begin 
	select dname into v_dname from dept where dno=:new.deptno;
	insert into sal_mod(empno, dname, old_sal, mod_date, modifier) values (:new.empno, v_dname, :old.sal, sysdate, user);
end;
/

/* Output:
	SQL> update emp set sal=32000 where empno=123;
	1 row updated.

	
	SQL> select * from sal_mod;
		 EMPNO DNAME         OLD_SAL MOD_DATE  MODIFIER
	---------- ---------- ---------- --------- -------------------------
		   123 Admin           32000 27-OCT-18 MCA9096
*/
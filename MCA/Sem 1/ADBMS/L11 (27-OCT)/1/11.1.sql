-- 11.1 Write a TRIGGER to ensure that DEPT TABLE does not contain duplicate of null values in DEPTNO column.

create or replace trigger tgr_deptno
	before insert or update of dno on dept1 for each row 
declare
	v_cnt	number(2);
begin
	select count(*) into v_cnt from dept where dno=:new.dno;	
	if :new.dno is null or v_cnt > 0 then
		raise_application_error(-20011, 'Invalid value for dno!');
	end if;
end;
/

/* Output:
Case- Duplicate dno value:
	SQL> insert into dept1 values ('D1', 'saas', 'CHN');
	insert into dept1 values ('D1', 'saas', 'CHN')
				*
	ERROR at line 1:
	ORA-20011: Invalid value for dno!
	ORA-06512: at "MCA9096.TGR_DEPTNO", line 6
	ORA-04088: error during execution of trigger 'MCA9096.TGR_DEPTNO'
	
Case- Null dno value: 
	SQL> insert into dept1 values (null, 'saas', 'CHN');
	insert into dept1 values (null, 'saas', 'CHN')
				*
	ERROR at line 1:
	ORA-20011: Invalid value for dno!
	ORA-06512: at "MCA9096.TGR_DEPTNO", line 6
	ORA-04088: error during execution of trigger 'MCA9096.TGR_DEPTNO'
*/
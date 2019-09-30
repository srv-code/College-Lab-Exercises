/*
	11.4 Write a PL/SQL block trigger to do INSERT/UPDATE/DELETE operation only
	during week days. Raise an exception if the day is SAT or SUN and also display
	user who initiated operation.
*/

create or replace trigger tgr_weekend_operation
	before delete or insert or update on emp
declare 
	v_weekday	varchar2(3);
begin 
	select to_char(sysdate, 'DY') into v_weekday from dual;
	if v_weekday = 'SUN' or v_weekday = 'SAT' then 
		raise_application_error(-20111, 'Cannot perform insert/update/delete operations on weekends!');
	end if;
end;
/

/* Output:
Case- While inserting into emp on a Saturday:
	SQL> insert into emp values (155, 'Sam', 'CLRK', 101, to_date('30-11-1883', 'dd-mm-yyyy'), 32000, 1500, 'D2', to_date('11-2-2000', 'dd-mm-yyyy'), 'P1');
	insert into emp values (155, 'Sam', 'CLRK', 101, to_date('30-11-1883', 'dd-mm-yyyy'), 32000, 1500, 'D2', to_date('11-2-2000', 'dd-mm-yyyy'), 'P1')
				*
	ERROR at line 1:
	ORA-20111: Cannot perform insert/update/delete operations on weekends!
	ORA-06512: at "MCA9096.TGR_WEEKEND_OPERATION", line 6
	ORA-04088: error during execution of trigger 'MCA9096.TGR_WEEKEND_OPERATION'
	
Case- While updating emp table on a Saturday:
	SQL> update emp set sal=25000 where empno=101;
	update emp set sal=25000 where empno=101
		   *
	ERROR at line 1:
	ORA-20111: Cannot perform insert/update/delete operations on weekends!
	ORA-06512: at "MCA9096.TGR_WEEKEND_OPERATION", line 6
	ORA-04088: error during execution of trigger 'MCA9096.TGR_WEEKEND_OPERATION'
	
Case- While deleting from emp on a Saturday:
	SQL> delete from emp where empno=101;
	delete from emp where empno=101
				*
	ERROR at line 1:
	ORA-20111: Cannot perform insert/update/delete operations on weekends!
	ORA-06512: at "MCA9096.TGR_WEEKEND_OPERATION", line 6
	ORA-04088: error during execution of trigger 'MCA9096.TGR_WEEKEND_OPERATION'
*/
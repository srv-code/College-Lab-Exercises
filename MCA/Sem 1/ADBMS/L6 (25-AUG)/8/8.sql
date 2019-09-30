-- 6.8 Insert a record into View EMP_PRJ_VW and check the underlying tables for result and confirm result with reason. 

insert into EMP_PRJ_VW values (199, 'sds', 'IT', 'P2', 'Prj_D5P2');

/* Output:
		ERROR at line 1:
		ORA-01779: cannot modify a column which maps to a non key-preserved table
	
	Reason: (check??)
		An attempt was made to insert or update columns of a join view which map to a non-key-preserved table. The view cannot be updated as it has columns from other tables as well.
*/
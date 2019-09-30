delete from dept 
	where dname = 'Marketing';
-- Output: 
-- 		ORA-02292: integrity constraint (SYSTEM.FK_DEPTNO_PROJ_ID) violated - child record found
-- Reason: 
-- 		Deletion failed as child records already existed in other tables (emp, proj) which needs to be deleted first.
-- 		Roll back not required as no operation was performed.

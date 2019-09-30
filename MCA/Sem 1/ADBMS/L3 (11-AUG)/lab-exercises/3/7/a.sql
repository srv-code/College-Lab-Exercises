update proj 
	set dno = 'D5' 
	where rownum = 1;
-- Output:
-- 		ORA-02292: integrity constraint (SYSTEM.FK_DEPTNO_PROJ_ID) violated - child record found
-- Reason: 
-- 		Update failed as child records already existed in other tables (emp, proj) which needs to be updated first.

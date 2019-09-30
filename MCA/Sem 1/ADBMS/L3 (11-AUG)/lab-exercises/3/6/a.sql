delete from emp 
	where mgr_id = 100 and prj_id = 'P1';
-- Output: 0 rows deleted.
-- Reason: No rows found with empno 100 due to the following constraint in emp table: empno > 100;
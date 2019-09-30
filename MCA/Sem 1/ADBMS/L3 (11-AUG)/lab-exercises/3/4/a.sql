-- 3.4 Run COMMIT command. Delete the employee records working on project P2 and confirm the result. Type ROLLBACK to restore the records back if records are deleted.

-- To commit previous commands:
commit;
-- Output: Commit complete.

-- To delete the employee records working on project P2:
delete from emp 
	where prj_id = ‘P2’;
-- Output: 3 rows deleted.


-- To confirm delete operation:
select count(*) from emp 
	where prj_id = ‘P2’;
-- Output:
--					 COUNT(*)
--	-------------------------
--							0
--	(Confirmed, no emp row for project id ‘P2’)

-- To rollback previous uncommitted commands:
rollback;
-- Output: Rollback complete.
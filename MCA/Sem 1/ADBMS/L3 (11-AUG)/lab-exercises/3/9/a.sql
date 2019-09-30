update emp 
	set comm = 10000 
	where job = 'MGR' and comm is null;
-- Output: 2 rows updated.
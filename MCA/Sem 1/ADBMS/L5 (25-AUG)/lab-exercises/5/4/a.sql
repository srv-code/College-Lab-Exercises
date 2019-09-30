-- 5.4 List the name of departments which are working with more than 1 project

/*
select d.dname 
	from proj p, dept d 
	where p.dno = d.dno 
	group by d.dname 
	having count(*) > 1;
*/
select dname from dept where dno in
	(select d.dno
		from proj p, dept d 
		where p.dno = d.dno 
		group by d.dno
		having count(*) > 1
	);
	

/* Output: 
	
DNAME
----------
Research
Marketing
*/
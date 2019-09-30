-- 5.13 List the Employees Name who is working at Locations (BNG,MUB,HYD)

select ename
	from emp e, dept d
	where d.location in ('BNG', 'MUB', 'HYD') and e.deptno = d.dno;

/* Output:

ENAME
----------
Aman
Raghu
Suman
Mahesh
*/
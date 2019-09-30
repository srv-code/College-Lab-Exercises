-- 5.5 Display department name, Max salary and Min salary in each department

select dname, max(sal), min(sal) 
	from emp e, dept d
	where e.deptno = d.dno
	group by d.dname;

/* Output: 

DNAME        MAX(SAL)   MIN(SAL)
---------- ---------- ----------
Research        88000      40000
Corporate
Marketing       32000      21000
Admin           75000      35000
*/
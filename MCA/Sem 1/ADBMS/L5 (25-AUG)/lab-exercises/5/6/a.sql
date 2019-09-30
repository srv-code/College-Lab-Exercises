-- 5.6 Display number of employees working in each department and their department name

select count(*) as "No of emp", d.dname 
	from emp e, dept d
	where e.deptno = d.dno 
	group by d.dname 
	having count(*) > 1;

/* Output:

 No of emp DNAME
---------- ----------
         4 Research
         5 Marketing
         5 Admin
*/
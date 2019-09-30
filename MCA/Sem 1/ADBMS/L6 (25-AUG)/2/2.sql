-- 6.2 Display name of the department from which maximum number of employees are working on project P1.



select dname from (select deptno, count(*) as c from emp where prj_id='P1' group by deptno order by 2 desc) x, dept d where ROWNUM=1 and d.dno=x.deptno;

/* Output: 
	DNAME
	----------
	Marketing
*/

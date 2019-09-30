-- 6.6 Create a View EMP_PRJ_VW to display records of employees of ‘marketing’ department and project in which they are working. 

create view emp_prj_vw as 
	select	empno, ename, dname, prj_id, prj_name 
		from emp e, dept d, proj p 
		where d.dname='Marketing' and e.deptno=d.dno and d.dno=p.dno;

/* Output:
	View created.
*/
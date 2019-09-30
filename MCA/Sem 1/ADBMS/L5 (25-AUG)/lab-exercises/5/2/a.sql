-- 5.2 List the Projects name undertaken by Marketing Department

select prj_name 
	from proj p, dept d
	where d.dname = 'Marketing' and d.dno = p.dno;
	
/* Output:
	PRJ_NAME
	----------
	Apex
*/	
-- 6.4 Display all employee names and salary whose salary is greater than minimum salary of the company.

select ename, sal from emp where sal > (select min(sal) from emp);

/* Output: 
	ENAME             SAL
	---------- ----------
	Ravi            32000
	Mahesh          35000
	Raviraj         24000
	Raghu           45000
					60000
	Priya           40000
	Suman           60000
	Aman            75000
	Trisha          75000
	Tanya           70000
	Virat           25000

	ENAME             SAL
	---------- ----------
	Umesh           28000
	Bardhan         88000

	13 rows selected.
*/
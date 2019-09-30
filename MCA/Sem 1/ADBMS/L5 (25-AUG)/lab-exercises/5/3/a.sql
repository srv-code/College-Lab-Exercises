-- 5.3 Display the employees name and salary in descending order by salary.

select ename, sal from emp
	order by sal desc;
	
/* Output:
	ENAME             SAL
	---------- ----------
	Manu
	Bardhan         88000
	Trisha          75000
	Aman            75000
	Tanya           70000
*/
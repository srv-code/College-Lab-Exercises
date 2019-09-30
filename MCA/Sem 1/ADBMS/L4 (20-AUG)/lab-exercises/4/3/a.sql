-- 4.3 List all employee with their names and their salaries, whose salary lies between 25200/- and 35200/- both inclusive.

select ename, sal from emp
	where sal between 25200 and 35200;

/* Output:

ENAME             SAL
---------- ----------
Ravi            32000
Mahesh          35000
*/
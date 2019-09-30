-- 5.1 List the minimum, maximum and average salaries and rename the column as min_sal,max_sal,avg_sal of the company

select	min(sal) as min_sal, 
		max(sal) as max_sal, 
		avg(sal) as avg_sal 
	from emp;

/* Output: 
   MIN_SAL    MAX_SAL    AVG_SAL
---------- ---------- ----------
     21000      88000 48428.5714
*/
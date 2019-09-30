-- 6.1 List Job category and total salary paid for the each jobs category by the company.

select job, sum(sal) from emp group by job;

/* Output: 
	JOB         SUM(SAL)
	--------- ----------
	CLRK           98000
	MGR           177000
	GM             45000
	CEO            60000
	A.MGR         298000
*/
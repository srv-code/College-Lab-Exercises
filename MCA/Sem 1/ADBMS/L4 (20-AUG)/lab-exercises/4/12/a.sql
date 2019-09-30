-- 4.12 List all kind of jobs available in employee table, avoid displaying duplicates

select distinct(job) from emp;

/* Output:

JOB
---------
CLRK
MGR
GM
CEO
A.MGR
*/

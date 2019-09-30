-- 4.9 List all employees reporting to manager with emp no 100.

select * from emp where mgr_id = 100;

/* Output: 

no rows selected

Reason: No rows found with empno 100 for the following constraint in EMP table: empno > 100
*/
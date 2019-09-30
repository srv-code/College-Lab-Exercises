-- 5.14 Update the COMM column of EMP table based on the SAL. Use
--  COMM=COMM+SAL*10/100

update emp
	set comm=comm+sal*10/100;

/* Output:

15 rows updated.
*/
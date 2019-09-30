-- 5.9 List the Employees who are born on a given year.

select * from emp
	where to_char(date_birth, 'YYYY') = &year;

/* Output:

Enter value for year: 1975
old   2:        where to_char(date_birth, 'YYYY') = &year
new   2:        where to_char(date_birth, 'YYYY') = 1975

     EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
       130 Virat      CLRK             101 10-OCT-75      25000       5000 D1  13-MAY-01 P1
       131 Umesh      CLRK             101 12-DEC-75      28000       5000 D1  13-MAY-03 P1
*/
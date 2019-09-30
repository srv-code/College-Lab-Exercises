-- 6.3 Select all employees from ‘Marketing’ and ‘Research’ dept.

select e.* from emp e, dept d where e.deptno=d.dno and d.dname = 'Marketing';

/* Output: 
		 EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
	---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
		   101 Ravi       MGR                  10-OCT-28      32000      13200 D1  02-OCT-01 P1
		   102 Raviraj    CLRK                 10-DEC-80      24000            D1  12-NOV-00 P1
		   120 Raman      CLRK             123 12-MAR-71      21000       7100 D1  13-MAY-01 P1
		   130 Virat      CLRK             101 10-OCT-75      25000       7500 D1  13-MAY-01 P1
		   131 Umesh      CLRK             101 12-DEC-75      28000       7800 D1  13-MAY-03 P1
*/
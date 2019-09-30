-- 4.10 List all employees whose name starts with either M or R.

select * from emp
	where ename like 'M%' or ename like 'R%';
	
/* Output:


     EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
       101 Ravi       MGR                  10-OCT-28      32000      10000 D1  02-OCT-01 P1
       123 Mahesh     MGR              111 10-DEC-74      35000      10000 D3  02-OCT-02 P2
       102 Raviraj    CLRK                 10-DEC-80      24000            D1  12-NOV-00 P1
       111 Raghu      GM                   10-DEC-74      45000      15000 D3  03-DEC-85 P2
       125 Manu       A.MGR                10-DEC-80                       D4  02-OCT-02 P3
*/
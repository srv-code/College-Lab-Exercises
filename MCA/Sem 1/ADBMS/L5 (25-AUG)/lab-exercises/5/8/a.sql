-- 5.8 List the Employees who are born in the month of December.

select * from emp
	where to_char(date_birth, 'MON') = 'DEC';
	
/* Output:

     EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
       123 Mahesh     MGR              111 10-DEC-74      35000      10000 D3  02-OCT-02 P2
       102 Raviraj    CLRK                 10-DEC-80      24000            D1  12-NOV-00 P1
       111 Raghu      GM                   10-DEC-74      45000      15000 D3  03-DEC-85 P2
       125 Manu       A.MGR                10-DEC-80                       D4  02-OCT-02 P3
       131 Umesh      CLRK             101 12-DEC-75      28000       5000 D1  13-MAY-03 P1

5 rows selected.
*/
-- 5.11 List the Employees having service experience more than 10 years.

select * from emp
	where (sysdate - date_of_join) > 3650;

/* Output:

     EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
       101 Ravi       MGR                  10-OCT-28      32000      10000 D1  02-OCT-01 P1
       123 Mahesh     MGR              111 10-DEC-74      35000      10000 D3  02-OCT-02 P2
       102 Raviraj    CLRK                 10-DEC-80      24000            D1  12-NOV-00 P1
       111 Raghu      GM                   10-DEC-74      45000      15000 D3  03-DEC-85 P2
       150            CEO                  10-DEC-70      60000      30000 D3  03-DEC-90 P2

5 rows selected.
*/
-- 4.1 Display all records from EMP, DEPT and PROJECTS table.

select * from emp;
/* Output:

     EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
       101 Ravi       MGR                  10-OCT-28      32000      10000 D1  02-OCT-01 P1
       123 Mahesh     MGR              111 10-DEC-74      35000      10000 D3  02-OCT-02 P2
       102 Raviraj    CLRK                 10-DEC-80      24000            D1  12-NOV-00 P1
       111 Raghu      GM                   10-DEC-74      45000      15000 D3  03-DEC-85 P2
       150            CEO                  10-DEC-70      60000      30000 D3  03-DEC-90 P2
       125 Manu       A.MGR                10-DEC-80                       D4  02-OCT-02 P3

6 rows selected.
*/

select * from dept;
/* Output:


DNO DNAME      LOCATION
--- ---------- ---------
D1  Marketing  CHN
D2  Reasearch  MNG
D5  IT         BNG
D3  Admin      BNG
D4  Corporate  MNG
*/

select * from proj;
/* Output:

DNO PRJ_N PRJ_NAME   PRJ_CREDITS STRT_DATE END_DATE
--- ----- ---------- ----------- --------- ---------
D1  P1                         2 20-AUG-01 22-FEB-06
D2  P1                         2 15-JUN-01 20-MAR-06
D3  P2                         2 21-DEC-01 15-MAY-06
D4  P3                         2 25-NOV-01 23-DEC-06
D5  P2                         2 20-FEB-01 22-SEP-06
*/
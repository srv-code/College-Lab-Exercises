-- 4.2 Display records of Employees who have salary more than 25000 or working in department D1

select * from emp
	where sal > 25000 or deptno = 'D1';
	
/* Output:


     EMPNO ENAME      JOB           MGR_ID DATE_BIRTH        SAL       COMM DEPTNO DATE_OF_JOIN PRJ_ID
---------- ---------- --------- ---------- ---------- ---------- ---------- ------ ------------ ------
       101 Ravi       MGR                  10-OCT-28       32000      10000 D1        02-OCT-01 P1
       123 Mahesh     MGR              111 10-DEC-74       35000      10000 D3        02-OCT-02 P2
       102 Raviraj    CLRK                 10-DEC-80       24000            D1        12-NOV-00 P1
       111 Raghu      GM                   10-DEC-74       45000      15000 D3        03-DEC-85 P2
       150            CEO                  10-DEC-70       60000      30000 D3        03-DEC-90 P2
*/
-- 6.5 Issue a query to find all the employees who work in the same job as Mahesh.

select * from emp where job = (select job from emp where ename='Mahesh');

/* Output: 
		 EMPNO ENAME      JOB           MGR_ID DATE_BIRT        SAL       COMM DEP DATE_OF_J PRJ_I
	---------- ---------- --------- ---------- --------- ---------- ---------- --- --------- -----
		   101 Ravi       MGR                  10-OCT-28      32000      13200 D1  02-OCT-01 P1
		   123 Mahesh     MGR              111 10-DEC-74      35000      13500 D3  02-OCT-02 P2
		   121 Priya      MGR              111 15-MAR-72      40000      16000 D2  13-MAY-01 P1
		   129 Tanya      MGR              126 11-OCT-71      70000      27000 D2  13-MAY-00 P1
*/
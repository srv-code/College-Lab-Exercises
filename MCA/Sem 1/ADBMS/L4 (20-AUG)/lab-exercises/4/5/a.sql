-- 4.5 Display Deptno from the table EMP avoiding the duplicated values.

select unique(deptno) from emp;

/* Output: 

DEP
---
D1
D3
D4
*/
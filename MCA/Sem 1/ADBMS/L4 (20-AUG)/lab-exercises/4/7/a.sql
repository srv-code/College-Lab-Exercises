-- 4.7 Create a manager table from the EMP table which should hold details only about the managers.

create table mgr as (select * from emp where job = 'MGR');

/* Output:

Table created.
*/
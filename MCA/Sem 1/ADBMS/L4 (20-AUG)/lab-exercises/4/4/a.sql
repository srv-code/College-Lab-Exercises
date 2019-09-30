-- 4.4 Create a pseudo table employee with the same structure as the table EMP and insert rows into the table using select clauses

create table employee as (select * from emp);

/* Output:

Table created.
*/
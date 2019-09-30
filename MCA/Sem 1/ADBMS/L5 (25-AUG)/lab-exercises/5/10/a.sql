-- 5.10 Display the DOB of all employees in the format “dd-mm-yy”.

select to_char(date_birth, 'dd-mm-yy') as dob from emp;

/* Output:

DOB
--------
10-10-28
10-12-74
10-12-80
10-12-74
10-12-70

5 rows selected.
 */
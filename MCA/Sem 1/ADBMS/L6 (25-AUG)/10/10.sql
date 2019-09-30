-- 6.10 Create an index on the columns (name and job) on EMP table.

create index emp_ename_job_idx on emp(ename, job);

/* Output:
	index created.
*/
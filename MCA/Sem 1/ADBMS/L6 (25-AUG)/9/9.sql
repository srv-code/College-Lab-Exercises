-- 6.9 Create a unique index on the column name DNAME on DEPT table.

create unique index dept_dname_uidx on dept(dname);

/* Output: (check??)
	index created.
*/
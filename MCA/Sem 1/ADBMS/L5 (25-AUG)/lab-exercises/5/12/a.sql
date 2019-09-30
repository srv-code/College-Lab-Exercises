-- 5.12 List the projects which have duration more than 1 year.

select * from proj
	where (end_date - strt_date) > 365;

/* Output:

DNO PRJ_N PRJ_NAME   PRJ_CREDITS STRT_DATE END_DATE
--- ----- ---------- ----------- --------- ---------
D1  P2    Alum                 3 20-MAY-93 21-FEB-19
D1  P3    Picasa               3 20-MAY-94 21-FEB-29
D2  P3    Cancel               2 20-MAY-94 21-FEB-29
D2  P2    Update               2 20-MAY-94 21-FEB-29

4 rows selected.
*/
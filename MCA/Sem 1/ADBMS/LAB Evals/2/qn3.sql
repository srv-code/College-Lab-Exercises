select * from Customer where custno in 
(
	select custno 
		from Orders 
		where orderdate between to_date('02-JAN-2017', 'DD-MON-YYYY') and to_date('02-SEP-2018', 'DD-MON-YYYY')
		group by custno 
		having count(*) >= 1
);
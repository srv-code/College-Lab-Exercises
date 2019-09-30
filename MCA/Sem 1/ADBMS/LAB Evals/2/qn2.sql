select c.cname
	from Customer c, Orders o
	where o.custno = o.custno 
		and to_char(o.orderdate, 'MON') = 'SEP';
select o.orderno, o.orderdate 
	from Customer c, Orders o 
	where		o.custno = c.custno
		and		c.city = 'Mumbai'; 
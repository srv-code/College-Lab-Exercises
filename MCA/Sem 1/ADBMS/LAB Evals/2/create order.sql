create table Orders
(
	orderno		varchar2(2) primary key,
	orderdate	date not null,
	custno		varchar2(2) references Customer(custno),
	itemno		varchar2(2) references Item(itemno),
	qty			number(5) not null
);
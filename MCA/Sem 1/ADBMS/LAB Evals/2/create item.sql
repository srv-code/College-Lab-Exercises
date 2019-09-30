create table Item 
(
	itemno		varchar2(2) primary key,
	itemname	varchar2(20) not null,
	unitprice	number(5,2) not null
);
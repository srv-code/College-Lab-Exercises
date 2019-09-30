create table test 
( 
	id number(1),
	name varchar2(2),
	constraint c check( id < 10 )
)
/
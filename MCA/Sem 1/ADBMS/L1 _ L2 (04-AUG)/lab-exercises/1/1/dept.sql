create table dept 
(
	dno			varchar2(3) primary key,
	dname 		varchar2(10) unique,
	location	varchar2(9) default 'BNG',	
	constraint check_dno check ( dno like 'D%' ),
	constraint check_location check ( location in ('BNG', 'MNG', 'MUB', 'HYD', 'CHN') )
);
/* O/P: Table created. */
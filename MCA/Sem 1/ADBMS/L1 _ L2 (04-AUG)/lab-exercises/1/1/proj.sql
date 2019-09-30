create table proj
(
	dno 			varchar2(3) not null references dept(dno) on delete cascade,
	prj_no 			varchar2(5) not null,
	prj_name		varchar2(10),
	prj_credits		number(2),
	strt_date 		date,
	end_date 		date,	
	constraint check_prj_no check (prj_no like 'P%'),
	constraint check_prj_credits check (prj_credits between 1 and 10),
	constraint check_end_date check (end_date > strt_date)
);
/* O/P: Table created. */
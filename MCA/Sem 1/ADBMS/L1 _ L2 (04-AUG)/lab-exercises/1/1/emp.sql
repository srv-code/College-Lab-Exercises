/*
create table emp 
(
	empno 			number(4),
	ename 			varchar2(10),
	job				varchar2(9) default 'CLRK',
	mgr_id 			number(4),
	date_birth 		date,
	sal 			number(7,2) default 20001,
	comm			number(7,2) default 1000,
	deptno 			varchar2(3),
	date_of_join	date,
	constraint fk_deptno_dno foreign key (deptno) references dept(dno),
	constraint check_job check (job in ('CLRK', 'MGR', 'A.MGR', 'GM', 'CEO')),
	constraint check_date_birth check (date_birth < date_of_join),
	constraint check_sal check (sal > 20000)
);
*/
/* O/P: Table created. */


/* 
alter table emp 
	add constraint pk_empno 
	primary key (empno); 
*/
/* O/P: Table altered. */

/*
alter table emp 
	add constraint fk_mgr_id_empno
	foreign key (mgr_id) 
	references emp(empno);
*/
/* O/P: Table altered. */
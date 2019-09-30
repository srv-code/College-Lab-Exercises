/* To check the constraint details associated with a table, user_cons_columns is a system table */
/* select owner, constraint_name, column_name from user_cons_columns where table_name='EMP'; */

/*
alter table emp 
	drop constraint fk_deptno_dno;
*/
/* O/P: Table altered. */

/*
alter table emp 
	add prj_id varchar2(5) not null; 
*/
/* O/P: Table altered. */

/*
alter table emp 
	add constraint fk_deptno_proj_id
	foreign key (deptno, prj_id) 
	references proj(dno, prj_no);
*/
/* O/P: Table altered. */
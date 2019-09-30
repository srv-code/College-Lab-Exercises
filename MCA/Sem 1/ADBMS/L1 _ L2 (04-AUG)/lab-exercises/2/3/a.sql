alter table emp
	add constraint check_empno 
	check (empno > 100);
/* O/P: Table altered. */
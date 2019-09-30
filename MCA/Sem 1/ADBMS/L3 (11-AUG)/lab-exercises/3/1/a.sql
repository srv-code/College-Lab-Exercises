-- 3.1 Insert records into EMP table.

--	* An valid values can be given to the columns left blank, columns with null must be entered with null values only.
--	* If some records cannot be inserted, give reasons.
--	* Insert 5 records of your own

-- insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (100, 'Ravi', 'MGR', 111, to_date('10-10-1928', 'DD-MM-YYYY'), 32000, null, 'D1', 'P1', to_date('02-10-2001', 'DD-MM-YYYY'));
-- Output: ORA-02290: check constraint (MCA9096.CHECK_EMPNO) violated

-- insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (101, 'Ravi', 'MGR', 111, to_date('10-10-1928', 'DD-MM-YYYY'), 32000, null, 'D1', 'P1', to_date('02-10-2001', 'DD-MM-YYYY'));
-- Output: ORA-02291: integrity constraint (MCA9096.FK_DEPTNO_PROJ_ID) violated - parent key not found

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (101, 'Ravi', 'MGR', null, to_date('10-10-1928', 'DD-MM-YYYY'), 32000, null, 'D1', 'P1', to_date('02-10-2001', 'DD-MM-YYYY'));
-- Output: 1 row created.

-- insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (102, 'Raviraj', 'CLRK', null, to_date('10-12-1980', 'DD-MM-YYYY'), 24000, null, 'D1', 'P3', to_date('12-11-2000', 'DD-MM-YYYY'));
-- Output: ORA-02291: integrity constraint (MCA9096.FK_DEPTNO_PROJ_ID) violated - parent key not found

-- insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (111, 'Raghu', 'GM', null, to_date('10-12-1974', 'DD-MM-YYYY'), 45000, 15000, null, null, to_date('03-12-1985', 'DD-MM-YYYY'));
-- Output: ORA-01400: cannot insert NULL into ("MCA9096"."EMP"."PRJ_ID")

-- insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (150, null, 'CEO', null, to_date('10-12-1970', 'DD-MM-YYYY'), 60000, 30000, null, null, to_date('03-12-1990', 'DD-MM-YYYY'));
-- Output: ORA-01400: cannot insert NULL into ("MCA9096"."EMP"."PRJ_ID")

-- insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (125, 'Manu', 'A.MGR', null, to_date('10-12-1980', 'DD-MM-YYYY'), null, null, 'D4', 'P2', to_date('02-10-2002', 'DD-MM-YYYY'));
-- Output: ORA-02291: integrity constraint (MCA9096.FK_DEPTNO_PROJ_ID) violated - parent key not found

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (120, 'Raman', 'CLRK', 123, to_date('12-03-1971', 'DD-MM-YYYY'), 21000, 5000, 'D1', to_date('13-05-2001', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (121, 'Priya', 'MGR', 111, to_date('15-03-1972', 'DD-MM-YYYY'), 40000, 12000, 'D2', to_date('13-05-2001', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (122, 'Suman', 'A.MGR', 150, to_date('15-08-1970', 'DD-MM-YYYY'), 60000, 20000, 'D3', to_date('13-05-2003', 'DD-MM-YYYY'), 'P2');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (124, 'Aman', 'A.MGR', 150, to_date('15-10-1972', 'DD-MM-YYYY'), 75000, 25000, 'D3', to_date('13-05-2003', 'DD-MM-YYYY'), 'P2');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (126, 'Trisha', 'A.MGR', 150, to_date('16-10-1973', 'DD-MM-YYYY'), 75000, 25000, 'D2', to_date('13-05-2003', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (129, 'Tanya', 'MGR', 126, to_date('11-10-1971', 'DD-MM-YYYY'), 70000, 20000, 'D2', to_date('13-05-2000', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (130, 'Virat', 'CLRK', 101, to_date('10-10-1975', 'DD-MM-YYYY'), 25000, 5000, 'D1', to_date('13-05-2001', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (131, 'Umesh', 'CLRK', 101, to_date('12-12-1975', 'DD-MM-YYYY'), 28000, 5000, 'D1', to_date('13-05-2003', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, date_of_join, prj_id) values (145, 'Bardhan', 'A.MGR', 150, to_date('14-02-1970', 'DD-MM-YYYY'), 88000, 30000, 'D2', to_date('13-01-2000', 'DD-MM-YYYY'), 'P1');
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (123, 'Mahesh', 'CLRK', null, to_date('10-12-1974', 'DD-MM-YYYY'), 25000, null, 'D3', 'P2', to_date('02-10-2002', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (102, 'Raviraj', 'CLRK', null, to_date('10-12-1980', 'DD-MM-YYYY'), 24000, null, 'D1', 'P1', to_date('12-11-2000', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (111, 'Raghu', 'GM', null, to_date('10-12-1974', 'DD-MM-YYYY'), 45000, 15000, 'D3', 'P2', to_date('03-12-1985', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (150, null, 'CEO', null, to_date('10-12-1970', 'DD-MM-YYYY'), 60000, 30000, 'D3', 'P2', to_date('03-12-1990', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into emp (empno, ename, job, mgr_id, date_birth, sal, comm, deptno, prj_id, date_of_join) values (125, 'Manu', 'A.MGR', null, to_date('10-12-1980', 'DD-MM-YYYY'), null, null, 'D4', 'P3', to_date('02-10-2002', 'DD-MM-YYYY'));
-- Output: 1 row created.

-- Inserting manager IDs (mgr_id):
update emp 
	set mgr_id = 111 
	where empno = 101;
-- Output: 1 row updated.

update emp 
	set mgr_id = 125 
	where empno = 123;
-- Output: 1 row updated.

update emp 
	set mgr_id = 125 
	where empno = 102;
-- Output: 1 row updated.
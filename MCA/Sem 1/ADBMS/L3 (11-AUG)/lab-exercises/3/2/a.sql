-- 3.2 Insert the following records into DEPT table. Write the reason if some records are not inserted. Insert 2 records of your own.

insert into dept (dno, dname, location) values ('D1', 'Marketing', 'CHN');
-- Output: 1 row created.

insert into dept (dno, dname, location) values ('D2', 'Reasearch', 'MNG');
-- Output: 1 row created.

-- insert into dept (dno, dname, location) values ('D3', 'Administrator', 'BNG');
-- Output: ORA-12899: value too large for column "MCA9096"."DEPT"."DNAME" (actual: 13, maximum: 10)

-- insert into dept (dno, dname, location) values ('D4', null, 'BGG');
-- Output: ORA-02290: check constraint (MCA9096.CHECK_LOCATION) violated

insert into dept (dno, dname, location) values ('D5', 'IT', 'BNG');
-- Output: 1 row created.

-- insert into dept (dno, dname, location) values (null, 'Corporate', 'HYD');
-- Output: ORA-01400: cannot insert NULL into ("MCA9096"."DEPT"."DNO")

insert into dept (dno, dname, location) values ('D3', 'Admin', 'BNG');
-- Output: 1 row created.

insert into dept (dno, dname, location) values ('D4', 'Corporate', 'MNG');
-- Output: 1 row created.
-- 3.3 Insert the following records into PROJ table. Write the reason if some records cannot be inserted. Insert 2 records of your own.

-- insert into proj (dno, prj_no, prj_name, prj_credits, strt_date, end_date) values ('D1', 'P1', null, 2, to_date('20-08-2003', 'DD-MM-YYYY'), to_date('22-02-2000', 'DD-MM-YYYY'));
-- Output: ORA-02290: check constraint (MCA9096.CHECK_END_DATE) violated

insert into proj (dno, prj_no, prj_name, prj_credits, strt_date, end_date) values ('D1', 'P1', null, 2, to_date('20-08-2001', 'DD-MM-YYYY'), to_date('22-02-2006', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into proj (dno, prj_no, prj_name, prj_credits, strt_date, end_date) values ('D2', 'P1', null, 2, to_date('15-06-2001', 'DD-MM-YYYY'), to_date('20-03-2006', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into proj (dno, prj_no, prj_name, prj_credits, strt_date, end_date) values ('D3', 'P2', null, 2, to_date('21-12-2001', 'DD-MM-YYYY'), to_date('15-05-2006', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into proj (dno, prj_no, prj_name, prj_credits, strt_date, end_date) values ('D4', 'P3', null, 2, to_date('25-11-2001', 'DD-MM-YYYY'), to_date('23-12-2006', 'DD-MM-YYYY'));
-- Output: 1 row created.

insert into proj (dno, prj_no, prj_name, prj_credits, strt_date, end_date) values ('D5', 'P2', null, 2, to_date('20-02-2001', 'DD-MM-YYYY'), to_date('22-09-2006', 'DD-MM-YYYY'));
-- Output: 1 row created.

/*
create table Policy 
(
	Policy_no		varchar2(10) primary key,
	Premium			number(7),
	Customer_Id		varchar2(10),
	Status			char(1),
	Pending_premium	number(1)
);
*/

/*
insert into Policy (Policy_no, Premium, Customer_Id, Pending_premium) values ('LIC_111', 10000, 'Cust_100', 1);
insert into Policy (Policy_no, Premium, Customer_Id, Pending_premium) values ('LIC_112', 15000, 'Cust_104', 2);
insert into Policy (Policy_no, Premium, Customer_Id, Pending_premium) values ('LIC_115', 30000, 'Cust_104', 5);
insert into Policy (Policy_no, Premium, Customer_Id, Pending_premium) values ('LIC_181', 10000, 'Cust_100', 3);
*/

set serveroutput on;

declare	
	v_custid	Policy.Customer_Id%type := '&customer_id';
	cursor cur_policy is 
		select *
			from Policy 
				where Customer_Id = v_custid;	
	v_prem		Policy.Pending_premium%type;
begin
	for v_cur_rec in cur_policy
	loop 
		v_prem := v_cur_rec.Pending_premium;
		if v_prem > 2 then
			update Policy
				set Status = 'B'
					where Customer_Id = v_custid and Policy_no = v_cur_rec.Policy_no;
			dbms_output.put_line('Dear ' || v_custid || ', you have policy ' || v_cur_rec.Policy_no || ' having Rupees ' || v_prem * v_cur_rec.Premium || ' due.');
		else 
			update Policy
				set Status = 'G'
					where Customer_Id = v_custid and Policy_no = v_cur_rec.Policy_no;
		end if;			
	end loop;
	commit;
end;
/
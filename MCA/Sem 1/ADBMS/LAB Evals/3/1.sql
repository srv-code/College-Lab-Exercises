set serveroutput on;

declare
	v_bid				book_issue.book_id%type := '&BookID';
	v_copies_avb		book_issue.copies%type;
	v_bname				book_issue.book_name%type;
begin
	select copies, book_name into v_copies_avb, v_bname
		from book_issue
		where book_id = v_bid;
			
	if v_copies_avb = 0 then
		dbms_output.put_line(v_bname || ' is currently not available.');
	else 
		v_copies_avb := v_copies_avb - 1;
		update book_issue 
			set copies = v_copies_avb
			where book_id = v_bid;
		commit;
		dbms_output.put_line(v_bname || ' is issued and Return Date is ' || to_char(sysdate + 7, 'DD Mon YYYY'));
	end if;
end;
/
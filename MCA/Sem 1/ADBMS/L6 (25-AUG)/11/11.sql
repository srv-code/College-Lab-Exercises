-- 6.11 Create a Sequence STUD_SEQ which starts from 100 to 999 with increments of 3.

create sequence stud_seq	
	start with 100
	maxvalue 999
	increment by 3;

/* Output:
	Sequence created.
*/
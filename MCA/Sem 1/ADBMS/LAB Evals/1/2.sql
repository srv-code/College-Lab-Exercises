alter table patient
	add Mobile_No number(10) check (length(Mobile_No) = 10);
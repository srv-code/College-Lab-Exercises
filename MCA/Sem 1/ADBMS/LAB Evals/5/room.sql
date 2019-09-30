create table Rooms_Reserved 
(
	Room_Type		varchar2(3) primary key,
	Tariff			number(4),
	No_Rooms_Available	number(2)	
);

create table Rooms_Requested 
(
	Request_ID		number(3) primary key,
	CustMailID		varchar2(15),
	CheckInDate		date,
	CheckOutDate	date,
	RoomType		varchar2(3),
	No_Of_Rooms		number(2)
);


insert into Rooms_Reserved values ('A', 5000, 10);
insert into Rooms_Reserved values ('B', 2000, 10);


create or replace trigger tgr_Room_Validation 
	before insert or delete on Rooms_Requested for each row 
declare 
	v_count 	number(3);
	v_tariff	Rooms_Reserved.Tariff%type;
begin 
	if inserting then 
		select count(*) into v_count from Rooms_Reserved where Room_Type = :new.RoomType;
		if (v_count = 0) then 
			raise_application_error(-20011, 'No such room available!');
		end if;
		
		select No_Rooms_Available into v_count from Rooms_Reserved where Room_Type = :new.RoomType;		
		if (v_count < :new.No_Of_Rooms) then 
			raise_application_error(-20011, :new.No_Of_Rooms || ' rooms not currently available for room type ' || :new.RoomType || '!');
		end if;
		
		select tariff into v_tariff from Rooms_Reserved where Room_Type = :new.RoomType;
		dbms_output.put_line('Tariff: Rs. ' || v_tariff * (:new.CheckOutDate - :new.CheckInDate));
		
		update Rooms_Reserved
			set No_Rooms_Available = No_Rooms_Available - :new.No_Of_Rooms
			where Room_Type = :new.RoomType;
		
	elsif deleting then
		update Rooms_Reserved
			set No_Rooms_Available = No_Rooms_Available + :old.No_Of_Rooms
			where Room_Type = :old.RoomType;
	end if;
end;
/

insert into Rooms_Requested values (2, 'aa', sysdate, sysdate+2, 'B', 2);

select * from Rooms_Requested;
select * from Rooms_Reserved;

delete from Rooms_Requested where Request_ID = 2;
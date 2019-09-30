declare 
	i number_table.num%type := 1;
begin
	loop 
		insert into number_table values(i);
		i := i + 1;
		exit when i > 10;
	end loop;
end;
/
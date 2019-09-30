set serveroutput on;

create or replace trigger t 
before insert or update of sal, deptno or delete on emp for each row
begin 
	case 
		when inserting then 
			dbms_output.put_line('Inserting');
			dbms_output.put_line(:new.empno);
		when updating('sal') then 
			dbms_output.put_line('Updating salary');
		when updating('deptno') then 
			dbms_output.put_line('Updating department ID');
		when deleting then 
			dbms_output.put_line('Deleting');
	end case;
end;
/

/*
	To see recent-most errors: show errors;
*/
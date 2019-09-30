/* Find the area of the circle */
set serveroutput on
declare 
	pi constant number := 3.14;
	v_radius number := 2;
	area number;
begin
	select radius into v_radius from circle where rownum = 1;

	area := pi*v_radius*v_radius;
	dbms_output.put_line('Area of circle=' || area);
end;
/
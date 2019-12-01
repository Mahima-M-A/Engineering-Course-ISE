-- Program to raise a trigger when EMPLOYEE table is modified on a particular day(here, saturday or sunday)

set serveroutput on;

create or replace trigger myTrigger3
before insert or delete or update on employee
begin
	if to_char(sysdate,'Dy') in ('Sat','Sun') then
		raise_application_error(-20520,'Not allowed');
	end if;
end;
/

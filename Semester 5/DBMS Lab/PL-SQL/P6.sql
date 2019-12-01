-- Program to find the factorial of the entered number using procedure.

set serveroutput on;

-- procedure
create or replace procedure fact(n in number,res out number) is
begin
	if n=0 or n=1 then
		res:=1;
	else
		fact(n-1,res);
		res:=res*n;
	end if;
end;
/

-- main program
declare
	n number:=&num;
	res number:=0;
begin
	fact(n,res);
	dbms_output.put_line('Factorial of '||n||' = '||res);
end;
/

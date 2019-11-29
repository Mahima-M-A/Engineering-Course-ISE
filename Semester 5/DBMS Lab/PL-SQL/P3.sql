set serveroutput on;

declare
	n1 number:=&num;
	flag number:=0;
	n number;
	r number;

begin
	n:=n1/2;
	for i in 2..n loop
		r:=mod(n1,i);
		if r=0 then
			flag:=1;
		end if;
	end loop;
	if flag=0 then
		dbms_output.put_line(n1||' is prime');
	else
		dbms_output.put_line(n1||' is not prime');
	end if;

end;
/

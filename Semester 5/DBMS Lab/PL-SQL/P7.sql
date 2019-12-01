-- To check if the entered number is a palindrome or not

set serveroutput on;

declare
	n number:=&num;
	temp number;
	r number;
	d number:=0;

begin
	temp:=n;
	while n>0 loop
		r:=mod(n,10);
		d:=(d*10)+r;
		n:=trunc(n/10);
	end loop;
	if d=temp then
		dbms_output.put_line(temp||' is a palindrome');
	else
		dbms_output.put_line(temp||' is not a palindrome');
	end if;

end;
/

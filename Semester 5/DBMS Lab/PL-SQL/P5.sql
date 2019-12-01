-- Program to print first 8 fibonacci numbers

set serveroutput on; 

declare
	f number:=0;
	s number:=1;
	t number;
	c1 number:=2;

begin
	dbms_output.put_line('First 8 fibonacci numbers are:'||chr(10)||f||chr(10)||s);
	while c1<8 loop
		t:=f+s;
		f:=s;
		s:=t;
		dbms_output.put_line(t);
		c1:=c1+1;
	end loop;

end;
/

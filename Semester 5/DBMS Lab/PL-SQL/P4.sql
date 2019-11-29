-- An empty table COPY with attributes same as an existing table(in this program - EMPLOYEE(SSN,Name,Sal,Deptno)) has to be created 

set serveroutput on;

declare
	cursor e_cursor is select * from employee;
	e_row e_cursor%rowtype;
	cursor c_cursor is select * from copy;
	c_row c_cursor%rowtype;

begin
	dbms_output.put_line(chr(10)||'****Copy table****'||chr(10));
	dbms_output.put_line('SSN  Name   Salary    DeptNo');
	for c_row in c_cursor loop
		dbms_output.put_line(c_row.ssn||'    '||c_row.name||'    '||c_row.sal||'      '||c_row.deptno);
	end loop;

end;
/

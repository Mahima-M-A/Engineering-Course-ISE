--An EMPLOYEE table with attributes SSN,Name,Salary,DeptNo and a few tuples needs to be created

set serveroutput on;

declare
    v_count number:=0;

begin
    update employee set sal = sal+0.15*sal where deptno=10;
    v_count:=SQL%rowcount;
    commit;
    dbms_output.put_line(chr(10)||'No. of employees awarded : '||v_count);

end;
/

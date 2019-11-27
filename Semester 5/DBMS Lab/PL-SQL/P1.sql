set serveroutput on;

declare
    cursor branch_cursor is select * from branch;
    b_row branch_cursor%rowtype;
    cursor cust_cursor is select * from customer;
    c_row cust_cursor%rowtype;
    cursor acc_cursor is select * from account;
    a_row acc_cursor%rowtype;
    acno char(2);

begin
    --to display contents of branch, customer and account tables.
    dbms_output.put_line(chr(10));
    dbms_output.put_line('***********Branch table ************');
    dbms_output.put_line('Code     Name      Assets');
    for b_row in branch_cursor loop
        dbms_output.put_line( b_row.code || '       ' || b_row.name || '       ' || b_row.assets);
    end loop;

    dbms_output.put_line(chr(10));
    dbms_output.put_line('***********Customer table ************');
    dbms_output.put_line('SSN     Name      Place');
    for c_row in cust_cursor loop
        dbms_output.put_line(c_row.ssn || '       ' || c_row.name || '       ' || c_row.place);
    end loop;

    dbms_output.put_line(chr(10));
    dbms_output.put_line('***********Account table ************');
    dbms_output.put_line('Accno     SSN      Code     Balance');
    for a_row in acc_cursor loop
        dbms_output.put_line( a_row.accno || '         '|| a_row.ssn || '       ' || a_row.code || '        ' || a_row.balance);
    end loop;

    --to update balance of a few accounts(here 'A2' and 'A5')
    dbms_output.put_line(chr(10)||'After updating balances of accno A2 and A5'||chr(10));
    dbms_output.put_line('Accno     SSN      Code     Balance');
    for a_row in acc_cursor loop
        if a_row.accno='A2' or a_row.accno='A5' then
            acno:=a_row.accno;
            update account set balance = balance+1000 where accno=acno;
        end if;
        dbms_output.put_line( a_row.accno || '         '|| a_row.ssn || '       ' || a_row.code || '        ' || a_row.balance);
    end loop;
end;
/

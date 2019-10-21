create table employee(
	ssn int primary key,
	name varchar(20),
	deptno int);

create table project(
	projectNo int primary key,
	projectArea varchar(20));

create table assigned_to(
	ssn int,
	projectNo int,
	primary key(ssn,projectNo),
	foreign key(ssn) references employee(ssn) on delete cascade,
	foreign key(projectNo) references project(projectNo) on delete cascade);

insert into employee values(1,'abc',10);
insert into employee values(2,'def',25);
insert into employee values(3,'pqr',25);

insert into project values(12,'database');
insert into project values(15,'robotics');
insert into project values(20,'automobile');

insert into assigned_to values(1,12);
insert into assigned_to values(2,12);
insert into assigned_to values(3,20);

select * from employee;
select * from project;
select * from assigned_to;

--a)--
select ssn from assigned_to,project
where projectArea='database'
and assigned_to.projectNo=project.projectNo;

--b)--
select deptNo,count(ssn) no_of_emp
from employee
group by deptNo;

--c)--
update assigned_to set projectNo=20 where ssn=1;
select * from assigned_to;

--d)--
select ssn,name from employee where deptNo=10;

--e)--
select name from employee,assigned_to
where projectNo=12
and employee.ssn=assigned_to.ssn;

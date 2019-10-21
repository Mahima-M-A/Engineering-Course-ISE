create table part(
	pno int primary key,
	pname varchar(20),
	colour varchar(20);

create table supplier(
	sno int primary key,
	sname varchar(20),
	address varchar(20));

create table supply(
	pno int,
	sno int,
	quantity int,
	primary key(pno,sno),
	foreign key(pno) references part(pno) on delete cascade,
	foreign key(sno) references supplier(sno) on delete cascade);

insert into part values(11,'bench','brown');
insert into part values(21,'bolt','silver');
insert into part values(24,'pen','green');

insert into supplier values(40,'Ram','Pune');
insert into supplier values(20,'Sam','Blr');
insert into supplier values(25,'Tom','TN');

insert into supply values(11,40,2);
insert into supply values(21,40,3);
insert into supply values(24,20,1);

select * from part;
select * from supplier;
select * from supply;

--a)--
select pno from supply,supplier
where sname='Ram'
and supply.sno=supplier.sno;

--b)--
select sname from supplier,supply,part
where pname='bolt'
and supplier.sno=supply.sno
and part.pno=supply.pno;

--c)--
delete from part where colour='green';
select * from part;

--e)--
select supplier.sno,sname from supplier,supply
where pno=11
and supplier.sno=supply.sno;

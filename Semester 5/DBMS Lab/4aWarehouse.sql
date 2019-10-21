create table parts(
	pno int primary key,
	pname varchar(20),
	colour varchar(20));

create table warehouse(
	wno int primary key,
	wname varchar(20),
	city varchar(10));

create table shipment(
	pno int,
	wno int,
	quantity int,
	date varchar(10),
	primary key(pno,wno),
	foreign key(pno) references parts(pno) on delete cascade,
	foreign key(wno) references warehouse(wno) on delete cascade);

insert into parts values(11,'bench','brown');
insert into parts values(21,'bolt','silver');
insert into parts values(24,'pen','red');

insert into warehouse values(20,'abc','Blr');
insert into warehouse values(25,'dfe','TN');
insert into warehouse values(40,'pqr','Pune');

insert into shipment values(11,40,2,'12/10/19');
insert into shipment values(21,40,3,'1/9/19');
insert into shipment values(24,20,1,'17/11/19');
insert into shipment values(21,20,1,'12/11/19');
insert into shipment values(21,25,1,'10/11/19');

select * from parts;
select * from warehouse;
select * from shipment;

--a)--
select wname from warehouse,parts,shipment
where colour='red'
and warehouse.wno=shipment.wno
and parts.pno=shipment.pno;

--b)--
select pno from shipment
group by pno
having count(wno)=(select count(wno) from warehouse);

--c)--
select wno,count(pno) no_of_parts from shipment
group by pno;

--d)--
select count(pno) no_of_parts from shipment,warehouse
where wname='abc'
group by shipment.wno;

--e)--
select wno,sum(quantity) total_qty from shipment 
group by wno;

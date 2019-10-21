create table boat(
	bid int primary key,
	bname varchar(20),
	colour varchar(20));

create table sailor(
	sid int primary key,
	sname varchar(20),
	age int,
	rating int);

create table reserves(
	bid int,
	sid int,
	day varchar(10),
	primary key(bid,sid),
	foreign key(bid) references boat(bid) on delete cascade,
	foreign key(sid) references sailor(sid) on delete cascade);

insert into boat values(1,'abc','white');
insert into boat values(2,'def','white');
insert into boat values(3,'gef','brown');

insert into sailor values(10,'Ram',25,3);
insert into sailor values(11,'Sam',35,2);
insert into sailor values(12,'Tom',32,4);

insert into reserves values(1,10,'monday');
insert into reserves values(1,11,'tuesday');
insert into reserves values(1,12,'friday');

select * from boat;
select * from sailor;
select * from reserves;

--a)--
select bid from reserves,sailor
where sname='Ram'
and reserves.sid=sailor.sid;

--b)--
select bid from reserves
group by bid
having count(sid)=(select count(sid) from sailor);

--c)--
select sid,count(bid) no_of_boats from reserves
group by sid;

--d)--
select count(bid) no_of_boats from reserves,sailor
where sname='Sam'
group by reserves.sid;

--e)--
select bid,bname from boat where colour='white';

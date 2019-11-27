create table branch(
	code char(2) primary key,
	name varchar(10),
	assets int);

create table customer(
	ssn int primary key,
	name varchar(10),
	place varchar(5));

create table account(
	accno char(2) primary key,
	ssn int,
	code char(2),
	balance int,
	foreign key (code) references branch(code) on delete cascade,
	foreign key (ssn) references customer(ssn) on delete cascade);

insert into branch values(&code,&name,&assets);
insert into customer values(&ssn,&name,&place);
insert into account values(&accno,&ssn,&code,&balance);

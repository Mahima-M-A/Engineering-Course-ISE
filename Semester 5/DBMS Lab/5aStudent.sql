create table book(
	isbn int primary key,
	title varchar(20),
	author varchar(20),
	publisher varchar(20));

create table student(
	usn int primary key,
	name varchar(20),
	sem int,
	deptno int);

create table borrow(
	isbn int,
	usn int,
	date varchar(10),
	primary key(isbn,usn),
	foreign key(isbn) references book(isbn) on delete cascade,
	foreign key(usn) references student(usn) on delete cascade);

insert into book values(110,'database','xyz','pqr');
insert into book values(115,'daa','sss','zzz');
insert into book values(123,'os','abc','xxx');

insert into student values(1,'aaa',3,50);
insert into student values(3,'bbb',5,20);
insert into student values(5,'ccc',7,20);

insert into borrow values(110,1,'12/10/19');
insert into borrow values(115,3,'13/10/19');
insert into borrow values(123,5,'14/10/19');

select * from book;
select * from student;
select * from borrow;

--a)--
select name from student,borrow
where isbn=123
and student.usn=borrow.usn;

--b)--
select name from student,book,borrow
where title='database'
and book.isbn=borrow.isbn
and student.usn=borrow.usn;

--c)--
select usn,count(isbn) no_of_books from borrow
group by usn;

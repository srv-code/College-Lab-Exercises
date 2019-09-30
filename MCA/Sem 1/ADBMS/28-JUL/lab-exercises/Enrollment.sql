create table Enrollment
(
	SID char (9) NOT NULL References Students, 
	CNo varchar2 (9) References Courses(CID),
	Year number (2) not null,
	Grade char (2),
	Primary key (SID, CNo, Year)
);

/*  
desc Enrollment;
 */

 /*  
select * from Enrollment;
 */
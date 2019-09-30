create table Doctor
(
	DocId		char(4),
	DocName 	varchar2(25) unique,
	Speciality 	char(10),
	Fees 		number(5,2),
	constraint pk_doctor_docid primary key (DocId),
	constraint check_docid check (DocId like 'D%'),
	constraint check_speciality check (Speciality in ('Skin', 'Ortho', 'Cardio')),
	constraint check_fees check (Fees between 150 and 500)
);
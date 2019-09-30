create table Patient 
(
	Patient_No 		number(5),
	Patient_Name 	varchar2(20),
	State			varchar2(25),
	DocId			char(4),
	constraint pk_patient_patient_no primary key (Patient_No),
	constraint fk_docid foreign key (DocId) references doctor(DocId)
);
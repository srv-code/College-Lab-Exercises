<?php 
	include_once('dbconnect.php');
	mysqli_query($con, 
		"delete from book where accession_no=$_GET[accno]"
	);
	header('Location: index.php');
?>
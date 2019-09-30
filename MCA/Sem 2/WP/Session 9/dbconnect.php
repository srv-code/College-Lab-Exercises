<?php 
	$servername = "localhost";
	$username = "root";
	$password = "";
	$db = "test";
	
	// Creating connection
	$conn = mysqli_connect($servername, $username, $password, $db);
	
	// Checking connection
	if(!$conn) 
		die("Connection failed: ". mysql_connect_error());
	echo "Connected successfully";
?>
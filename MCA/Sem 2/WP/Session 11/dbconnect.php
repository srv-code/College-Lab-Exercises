<?php
	$host = 'localhost';
	$user = 'root';
	$pwd = '';
	$db = 'LibraryDB';

	$con = mysqli_connect($host, $user, $pwd, $db);

	if(mysqli_connect_error()) {
		echo "Err: Cannot connect to DB: ". mysqli_connect_error() ."<br>";
		return;
	}
?>
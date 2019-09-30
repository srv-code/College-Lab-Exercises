<?php 
	session_start();
	if(isset($_SESSION['views'])) {
		$_SESSION['views'] = $_SESSION['views'] + 1;
	} else {
		$_SESSION['views'] = 1;
	}
	
	echo 'Views: ' . $_SESSION['views'];
?>

<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>PHP Session Count Demo</title>
	</head>
	<body>
		<br/>
			<a href="sessioncount2.php">Link</a>
		<br/>
	</body>
</html>
<?php 
	if(isset($_COOKIE['lastVisit'])) {
		$lastVisit = "<p>Your last visit was on " . $_COOKIE['lastVisit'] . "</p>";
	} else {
		$lastVisit = "<p>This is your first visit!</p>";		
	}
	
	setcookie("lastVisit", date("F, j, Y , g:i a"), time()+60*60*24*365);
?>

<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>PHP Cookie Demo</title>		
	</head>
	<body>
		<?php echo $lastVisit; ?>
	</body>
</html>
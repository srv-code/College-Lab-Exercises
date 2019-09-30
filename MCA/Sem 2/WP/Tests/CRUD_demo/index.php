<?php
	include_once("config.php");
	$result = mysqli_query($mysqli, "SELECT * FROM users ORDER BY id DESC");
?>

<html>
	<head>
		<title>Homepage</title>
	</head>
	<body>
		<a href="add.php">Add New User</a><br/><br/>
		<table width='80%' border=1>
		<tr>
			<th>ID</th>
			<th>Name</th>
			<th>Mobile</th>
			<th>Email</th>
			<th>Operations</th>
		</tr>
		<?php
			$rows=0;
			while($user_data = mysqli_fetch_array($result)) {
				$rows++;
				echo "  <tr>\n";
				echo "    <td>".$user_data['id']."</td>\n";
				echo "    <td>".$user_data['name']."</td>\n";
				echo "    <td>".$user_data['mobile']."</td>\n";
				echo "    <td>".$user_data['email']."</td>\n";
				echo "    <td><a href='edit.php?id=$user_data[id]'>Edit</a> | <a href='delete.php?id=$user_data[id]'>Delete</a></td>\n";
				echo "  </tr>\n";
			}

			if($rows > 0) {
				echo "<a href='search.php'>Search users</a>\n";
			}
		?>
		</table>
	</body>
</html>
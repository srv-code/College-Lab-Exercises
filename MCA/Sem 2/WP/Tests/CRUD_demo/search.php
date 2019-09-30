<html>
	<head>
		<title>Search Users</title>
		<script>
			window.onload = function() {
				document.forms['form1'].txtName.focus();
			};
		</script>
		<style>
			.result {
				border: 1px solid blue;
				border-collapse: collapse;
			}
		</style>
	</head>
	<body>
		<a href="index.php">Go to Home</a>
		<br/><br/>
		<form action="search.php" method="post" name="form1">
			<table width="25%" border="0">
				<tr>
					<td>Search</td>
					<td><input type="text" name="name" id="txtName"></td>
				</tr>				
				<tr> 
					<td></td>
					<td><input type="submit" name="Submit" value="Search"></td>
				</tr>
			</table>

			<?php
				// if(isset($_POST['name']))
					// echo "  // name= " . $_POST['name'] . " <br>";

				if(isset($_POST['Submit'])) {
					include_once("config.php");
					// echo "  // Submit=" . $_POST['Submit'] . " <br>";
					$query = "SELECT * FROM users where name='$_POST[name]' ORDER BY id";
					// echo "  // query=$query <br>";
					$result = mysqli_query($mysqli, $query);

					echo "<table class='result'>\n";
					while($user_data = mysqli_fetch_array($result)) {
						echo "  <tr>\n";
						echo "    <td class='result'>".$user_data['id']."</td>\n";
						echo "    <td class='result'>".$user_data['name']."</td>\n";
						echo "    <td class='result'>".$user_data['email']."</td>\n";
						echo "    <td class='result'>".$user_data['mobile']."</td>\n";
						echo "  </tr>\n";
					}
					echo "</table>\n";
				}
			?>
		</form>
	</body>
</html>
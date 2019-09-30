<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>Search books</title>
		<link rel="stylesheet" type="text/css" href="styles.css" />
		<script type="text/javascript">
			window.onload = function() {
				document.forms['formSearchBook'].txtTitle.focus();
			};

			function validateInput(form) {
				if(form.txtTitle.value.trim() === '') {
					alert('Please enter non-blank input!');
					return false;
				}
				return true;
			}
		</script>
	</head>
	<body>
		<a href="index.php">Homepage</a> <br> <br>
		<form name="formSearchBook" method="post" action="search.php" onsubmit="return validateInput(this);">
			Title: <input type="text" name="txtTitle" />
			<input type='submit' name='operation' value='Search' /> <br>
			
				<?php 
					include_once('dbconnect.php');
					if(isset($_POST['operation'])) {
						$result_set = mysqli_query($con, "select * from book where title='$_POST[txtTitle]'");
						$row_count=0;
						while($book_info = mysqli_fetch_array($result_set)) {
							$row_count++;
							echo "<br> \n";
							echo "<table> \n";
							echo "  <tr> \n";
							echo "    <th colspan='2'>Book Info</th> \n";
							echo "  </tr> \n";

							echo "  <tr> \n";
							echo "    <td>Title</td> \n";
							echo "    <td>$book_info[title]</td> \n";
							echo "  </tr> \n";
							
							echo "  <tr> \n";
							echo "    <td>Authors</td> \n";
							echo "    <td>$book_info[authors]</td> \n";
							echo "  </tr> \n";
							
							echo "  <tr> \n";
							echo "    <td>Edition</td> \n";
							echo "    <td>$book_info[edition]</td> \n";
							echo "  </tr> \n";
							
							echo "  <tr> \n";
							echo "    <td>Publisher</td> \n";
							echo "    <td>$book_info[publisher]</td> \n";
							echo "  </tr> \n";
							echo "</table> \n";
						}

						if($row_count > 0) 
							echo "<br> $row_count results found";
						else 
							echo "<br> No match found!";
					}

					mysqli_close($con);
				?>

			</table>
		</form>
	</body>
</html>
<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>Add new book</title>
		<script type="text/javascript" language="javascript">
			window.onload = function() {
				document.forms['formAddNewBook'].txtTitle.focus();
			};

			function validateForm(form) {
				with(form) {
					if(	txtTitle.value.trim() === '' ||
						txtAuthors.value.trim() === '' ||
						txtEdition.value.trim() === '' ||
						txtPublisher.value.trim() === '') {
						alert('Please fill in all fields!');
						return false;
					}
					return true;
				}
			}
		</script>
	</head>
	<body>
		<a href="index.php">Homepage</a>
		<form name="formAddNewBook" action="add.php" method="post" onsubmit="return validateForm(this);">
			<table>
				<tr>
					<th colspan="2" style="border: 2px solid black;">Book info</th>
				</tr>
				<tr>
					<tr>
					  <td>Title</td>
					  <td><input type="text" name="txtTitle" /></td>
					</tr>

					<tr>
					  <td>Authors</td>
					  <td><input type="text" name="txtAuthors" /></td>
					</tr>

					<tr>
					  <td>Edition</td>
					  <td><input type="text" name="txtEdition" /></td>
					</tr>

					<tr>
					  <td>Publisher</td>
					  <td><input type="text" name="txtPublisher" /></td>
					</tr>
				</tr>
				<tr>
					<td></td>
					<td><input type="submit" name="operation" value="Add" /></td>
				</tr>
			</table>
		</form>
		

		<?php 
			if(isset($_POST['operation'])) {
				include_once('dbconnect.php');
				$res = mysqli_query($con, "insert into book(title, authors, edition, publisher) values ('$_POST[txtTitle]', '$_POST[txtAuthors]', $_POST[txtEdition], '$_POST[txtPublisher]')");
				mysqli_close($con);
				
				if(!$res) {
					echo "Err: Cannot add book to database! <br>";
					return;
				}
				echo "Book added successfully! <br>";
			}
		?>
	</body>
</html>
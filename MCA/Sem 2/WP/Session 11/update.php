<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>Update book info</title>
		<link rel="stylesheet" type="text/css" href="styles.css" />
		<script type="text/javascript">
			window.onload = function() {
				var elm = document.forms['formUpdateBookInfo'].txtTitle;
				if(elm !== null)
					elm.focus();
			};
		</script>
	</head>
	<body>
		<form name="formUpdateBookInfo" action="update.php" method="post">
			<table>
				<tr>
					<th colspan="2">Book info</th>
				</tr>
				<?php 
					include_once('dbconnect.php');

					if(isset($_POST['operation'])) {
						// echo "txtAccNo=$_POST[txtAccNo] <br>";
						mysqli_query($con,	
										"update book 
											set 	title='$_POST[txtTitle]', 
													authors='$_POST[txtAuthors]', 
													edition=$_POST[txtEdition], 
													publisher='$_POST[txtPublisher]' 
														where accession_no=$_POST[txtAccNo]");
						/*
						echo "stat=$stat <br>";
						if($stat) 
							echo "Update succ";
						else
							echo "Update succ";
						*/
						
						header("Location: index.php");
					} else {
						$accno = $_GET['accno'];
						if($book_info = mysqli_fetch_array(mysqli_query($con, "select * from book where accession_no=$accno"))) {
							echo "  <tr> \n";
							echo "    <td>Acc No</td> \n";
							echo "    <td><input name='txtAccNo' readonly value='". $accno ."' /></td> \n";
							echo "  </tr> \n";
							
							echo "  <tr> \n";
							echo "    <td>Title</td> \n";
							echo "    <td><input name='txtTitle' value='". $book_info['title'] ."' /></td> \n";
							echo "  </tr> \n";

							echo "  <tr> \n";
							echo "    <td>Authors</td> \n";
							echo "    <td><input name='txtAuthors' value='". $book_info['authors'] ."' /></td> \n";
							echo "  </tr> \n";

							echo "  <tr> \n";
							echo "    <td>Edition</td> \n";
							echo "    <td><input name='txtEdition' value='". $book_info['edition'] ."' /></td> \n";
							echo "  </tr> \n";

							echo "  <tr> \n";
							echo "    <td>Publisher</td> \n";
							echo "    <td><input name='txtPublisher' value='". $book_info['publisher'] ."' /></td> \n";
							echo "  </tr> \n";

							$_POST['accno'] = $accno;
							echo "  <tr> \n";
							echo "    <th colspan='2'><input type='submit' name='operation' value='Update' /></th> \n";
							echo "  </tr> \n";
						} else {
							echo "  <tr> \n";
							echo "    <td colspan='2'>No books found!</td> \n";
							echo "  </tr> \n";
						}
					}
					mysqli_close($con);
				?>
			</table>
		</form>
	</body>
</html>
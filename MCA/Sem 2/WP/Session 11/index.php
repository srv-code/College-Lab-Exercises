<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>Homepage</title>
		<link rel="stylesheet" type="text/css" href="styles.css" />
	</head>
	<body>
		<ul>
			<li> <a href="add.php">Add books</a> </li>
			<li> <a href="search.php">Search books</a> </li>
		</ul>

		<table>
			<tr>
				<th>Title</th>
				<th>Authors</th>
				<th>Edition</th>
				<th>Publisher</th>
				<th>Operations</th>
			</tr>
			<?php
				include_once('dbconnect.php');
				$result_set = mysqli_query($con, "select * from book");
				while($book_info = mysqli_fetch_array($result_set)) {
					echo "  <tr class='cell_style'> \n";
					echo "    <td>$book_info[title]</td> \n";
					echo "    <td>$book_info[authors]</td> \n";
					echo "    <td>$book_info[edition]</td> \n";
					echo "    <td>$book_info[publisher]</td> \n";
					echo "    <td>".
						"<a href='update.php?accno=$book_info[accession_no]'>Update</a> | " .
						"<a href='delete.php?accno=$book_info[accession_no]'>Delete</a> ".
						"</td> \n";
					echo "  </tr> \n";
				}
			?>
		</table>
	</body>
</html>
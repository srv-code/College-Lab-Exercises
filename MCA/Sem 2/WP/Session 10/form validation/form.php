<!DOCTYPE HTML>
<html lang="en">
	<head>
		<title>Registration form</title>
		<link rel="stylesheet" type="text/css" href="form_styles.css" />
		<script src="validate_form.js" type="text/javascript" language="javascript"></script>
	</head>
	<body>
		<div id="mainContainer">
			<form id="formRegistration" method="post" action="form.php" onsubmit="return validateInputFields(this);" >
			<!-- <form id="formRegistration" method="post" action="form.php"> -->
				<table>
					<th colspan="3">
						Register yourself
					</th>

					<tr>
						<td colspan="3" class="separatorRow"></td>
					</tr>

					<tr>
						<td>
							Name:
						</td>
						<td>
							<input type="text" id="txtName" name="txtName" placeholder="Name" />
						</td>
						<td>
							*
							<img id="nameValidIndicator" class="validIndicator" />
							<span id="nameErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Address:
						</td>
						<td>
							<input type="text" id="txtAddress" name="txtAddress" placeholder="Address" />
						</td>
						<td>
							*
							<img id="addressValidIndicator" class="validIndicator" />
							<span id="addressErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Zip Code:
						</td>
						<td>
							<input type="text" id="txtZipCode" name="txtZipCode" placeholder="Zip code" />
						</td>
						<td>
							*
							<img id="zipcodeValidIndicator" class="validIndicator" />
							<span id="zipcodeErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Country:
						</td>
						<td>
							<select id="dropdownCountry" name="dropdownCountry">
								<option value=""></option>
								<option value="India">India</option>
								<option value="France">France</option>
								<option value="China">China</option>
								<option value="United States of America">United States of America</option>
							</select>
						</td>
						<td>
							*
							<img id="countryValidIndicator" class="validIndicator" />
							<span id="countryErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Gender:
						</td>
						<td>
							<input type="radio" name="gender" id="genderMale" value="m" /> 
								<label for="genderMale" class="subitem">Male</label>
							<input type="radio" name="gender" id="genderFemale" value="f" /> 
								<label for="genderFemale" class="subitem">Female</label>
						</td>
						<td>
							*
							<img id="genderValidIndicator" class="validIndicator" />
							<span id="genderErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Preferences:
						</td>
						<td>
							<input type="checkbox" name="prefColorRed" id="prefColorRed" value="red" /> 
								<label for="prefColorRed" class="subitem">Red</label>
							<input type="checkbox" name="prefColorGreen" id="prefColorGreen" value="green" /> 
								<label for="prefColorGreen" class="subitem">Green</label>
							<input type="checkbox" name="prefColorBlue" id="prefColorBlue" value="blue" /> 
								<label for="prefColorBlue" class="subitem">Blue</label>
						</td>
						<td>
							*
							<img id="prefValidIndicator" class="validIndicator" />
							<span id="prefErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Email ID:
						</td>
						<td>
							<input type="email" id="txtEmail" name="txtEmail" placeholder="Email ID" />
						</td>
						<td>
							*
							<img id="emailValidIndicator" class="validIndicator" />
							<span id="emailErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Phone Number:
						</td>
						<td>
							<input type="tel" id="txtPhoneNo" name="txtPhoneNo" placeholder="Phone number" />
						</td>
						<td>
							*
							<img id="phonenoIndicator" class="validIndicator" />
							<span id="phonenoErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Password:
						</td>
						<td>
							<input type="password" id="txtPwd" name="txtPwd" placeholder="Password" autocomplete="off" />
						</td>
						<td>
							*
							<img id="pwdValidIndicator" class="validIndicator" />
							<span id="pwdErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td>
							Verify password:
						</td>
						<td>
							<input type="password" id="txtVerifyPwd" name="txtVerifyPwd" placeholder="Verify password" autocomplete="off" />
						</td>
						<td>
							*
							<img id="verifyPwdValidIndicator" class="validIndicator" />
							<span id="verifyPwdErrorMsg" ></span>
						</td>
					</tr>
					
					<tr>
						<td colspan="3" class="separatorRow"></td>
					</tr>

					<tr>
						<td colspan="3" id="buttonsArea">
							<!-- <input type="button" value="Submit" onclick="return validateInputFields(document.forms['formRegistration']);" /> -->
							<input type="submit" name="Submit" value="Submit" />
							<input type="reset" value="Reset" onclick="clearForm();" />
							<!-- <input type="reset" value="Reset" onclick="clearInputFields();" /> -->
						</td>
					</tr>

					<?php 
						// init connection
						$host = 'localhost';
						$user = 'root';
						$pwd = '';
						$db = 'test96';
						$con = mysqli_connect($host, $user, $pwd, $db);

						// Check connection
						if (mysqli_connect_errno()) {
							echo "Err: Failed to connect to MySQL: " . mysqli_connect_error() . "<br>";
							return;
						}
						// echo "DB connection was successful! <br>";

						// for DB insertion

						if(isset($_POST['Submit'])) {
							$pref = '';
							if(isset($_POST['prefColorRed']))
								$pref .= 'r';
							if(isset($_POST['prefColorGreen']))
								$pref .= 'g';
							if(isset($_POST['prefColorBlue']))
								$pref .= 'b';
							
							// echo "pref=$pref <br>";

							$result = mysqli_query($con, "insert into users (name, address, zip, country, gender, preferences, email, phone, pwd) VALUES ('$_POST[txtName]', '$_POST[txtAddress]', $_POST[txtZipCode], '$_POST[dropdownCountry]', '$_POST[gender]', '$pref', '$_POST[txtEmail]', '$_POST[txtPhoneNo]', '$_POST[txtPwd]')");
						}
					?>
				</table>
			</form>
		</div>
	</body>
</html>
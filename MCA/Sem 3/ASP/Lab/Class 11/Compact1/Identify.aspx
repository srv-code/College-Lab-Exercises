<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Identify.aspx.cs" Inherits="Identify" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Login Page</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
    <div>
		<fieldset>
			<legend>Login</legend>
			<table>
				<tr>
					<td>Username</td>
					<td>
						<asp:TextBox ID="TextBox_Username" runat="server"></asp:TextBox>
					</td>
				</tr>
				<tr>
					<td>Password</td>
					<td>
						<asp:TextBox ID="TextBox_Password" TextMode="Password" runat="server"></asp:TextBox>
					</td>
				</tr>
				<tr>
					<td colspan="2">
						<asp:Button ID="Button_Login" runat="server" Text="Login" 
							onclick="Button_Login_Click" />
					</td>
				</tr>
			</table>
			<asp:Label ID="Label_Error" runat="server" ForeColor="Red"></asp:Label>
		</fieldset>	
    </div>
    </form>
</body>
</html>

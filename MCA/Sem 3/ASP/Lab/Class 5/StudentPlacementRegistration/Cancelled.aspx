<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Cancelled.aspx.cs" Inherits="CancellationPage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Cancellation Page</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
		<div>
			<div class="header">Registration cancelled</div>
			<asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/RegistrationForm.aspx">Go back to form</asp:HyperLink> <br>
            <asp:HyperLink ID="HyperLink2" runat="server" NavigateUrl="~/RegistrationData.aspx">View registration data</asp:HyperLink>
		</div>
    </form>
</body>
</html>

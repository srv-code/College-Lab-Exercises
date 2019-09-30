<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Test1.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>[Test] 1</title>
    <link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" defaultbutton="Button_Submit" runat="server">
        <div>
            <div>
                <asp:TextBox ID="TextBox_Data" ReadOnly="true" TextMode="MultiLine" 
                    runat="server" CssClass="text_output"></asp:TextBox>
				<asp:CustomValidator ID="CustomValidator1" runat="server" ErrorMessage="CustomValidator"></asp:CustomValidator>
            </div>
            <asp:Button ID="Button_Submit" runat="server" Text="Submit" 
                onclick="Button_Submit_Click" />
        </div>
    </form>
</body>
</html>

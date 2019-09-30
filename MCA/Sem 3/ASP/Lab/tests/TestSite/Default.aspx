<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Test</title>
</head>
<body>
    <form id="form1" defaultbutton="Button1" runat="server">
        <div>
            <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
                onselectedindexchanged="DropDownList1_SelectedIndexChanged">
                <asp:ListItem>a</asp:ListItem>
                <asp:ListItem>b</asp:ListItem>
            </asp:DropDownList>
        </div>
    <asp:TextBox ID="TextBox1" runat="server" AutoPostBack="True" 
            ontextchanged="TextBox1_TextChanged"></asp:TextBox>
    <asp:RadioButton ID="RadioButton1" runat="server" Text="A" GroupName="radio1" />
    <asp:RadioButton ID="RadioButton2" runat="server" Text="B" GroupName="radio1" />
        <p>
            <asp:Button ID="Button1" runat="server" Text="Button" 
                onclick="Button1_Click" oncommand="Button1_Command" CommandArgument="arg1" CommandName="cmd1">
            </asp:Button>
        </p>
    </form>
</body>
</html>

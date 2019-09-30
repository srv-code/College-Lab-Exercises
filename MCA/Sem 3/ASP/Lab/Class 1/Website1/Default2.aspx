<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" Trace="true" Title="MyPage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label> <br/>
            <asp:Button ID="Button1" runat="server" Text="Press Me" onclick="Button1_Click" />
        </div>
        
        <asp:LinkButton ID="LinkButton1" runat="server" onclick="LinkButton1_Click">LinkButton</asp:LinkButton> <br/>
        <asp:TextBox ID="TextBox1" runat="server" style="margin-top: 0px" 
            TextMode="MultiLine"></asp:TextBox> <br />
        <asp:ImageButton ID="ImageButton1" runat="server" 
            onclick="ImageButton1_Click" />
    </form>
</body>
</html>

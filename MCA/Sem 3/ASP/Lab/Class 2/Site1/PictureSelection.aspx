<%@ Page Language="C#" AutoEventWireup="true" CodeFile="PictureSelection.aspx.cs" Inherits="PictureSelection" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:ImageButton ID="ImageButton1" runat="server" 
                ImageUrl="~/Images/img (1).png" onclick="ImageButton1_Click" />
            <asp:ImageButton ID="ImageButton2" runat="server" 
                ImageUrl="~/Images/img (2).png" onclick="ImageButton1_Click" />
            <asp:ImageButton ID="ImageButton3" runat="server" 
                ImageUrl="~/Images/img (3).png" onclick="ImageButton1_Click" />
            <asp:ImageButton ID="ImageButton4" runat="server" 
                ImageUrl="~/Images/img (4).png" onclick="ImageButton1_Click" />
            <asp:ImageButton ID="ImageButton5" runat="server" 
                ImageUrl="~/Images/img (5).png" onclick="ImageButton1_Click" />
        </div>
        <div>
            <asp:ImageButton ID="ImageButton_Big" runat="server" 
                onclick="ImageButton_Big_Click" />
        </div>
    </form>
</body>
</html>

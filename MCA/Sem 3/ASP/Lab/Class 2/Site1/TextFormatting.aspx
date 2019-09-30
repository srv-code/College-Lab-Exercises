<%@ Page Language="C#" AutoEventWireup="true" CodeFile="TextFormatting.aspx.cs" Inherits="TextFormatting" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Text formatting</title>
    <link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table>
                <tr>
                    <td>Name</td>
                    <td><asp:TextBox ID="TextBox_Name" placeholder="Name" runat="server"></asp:TextBox></td>
                </tr>
                <tr>
                    <td>Text</td>
                    <td><asp:TextBox ID="TextBox_Text" placeholder="Text" runat="server"></asp:TextBox></td>
                </tr>
            </table>

            <div class="sub-heading">Fore color:</div>
            <asp:RadioButtonList ID="RadioButtonList_ForeColors" runat="server">
                <asp:ListItem>White</asp:ListItem>
                <asp:ListItem>Black</asp:ListItem>
                <asp:ListItem>Red</asp:ListItem>
                <asp:ListItem>Green</asp:ListItem>
                <asp:ListItem>Blue</asp:ListItem>
            </asp:RadioButtonList>

            <div class="sub-heading">Back color:</div>
            <asp:RadioButtonList ID="RadioButtonList_BackColors" runat="server">
                <asp:ListItem>White</asp:ListItem>
                <asp:ListItem>Black</asp:ListItem>
                <asp:ListItem>Red</asp:ListItem>
                <asp:ListItem>Green</asp:ListItem>
                <asp:ListItem>Blue</asp:ListItem>
            </asp:RadioButtonList>

            <div class="sub-heading">Styles:</div>
            <asp:CheckBox ID="CheckBox_Bold" runat="server" Text="Bold" /> <br>
            <asp:CheckBox ID="CheckBox_Italic" runat="server" Text="Italic" /> <br>
            <asp:CheckBox ID="CheckBox_Underline" runat="server" Text="Underline" /> <br>
            
            <div style="margin-top: 5px; margin-bottom: 20px;">
                <asp:Button ID="Button_Apply" runat="server" Text="Apply" 
                    onclick="Button_Apply_Click" />
            </div>

            <div class="sub-heading">Output:</div>
            <asp:TextBox ID="TextBox_Output" CssClass="result" runat="server" 
                ReadOnly="True" TextMode="MultiLine"></asp:TextBox>
        </div>
    </form>
</body>
</html>

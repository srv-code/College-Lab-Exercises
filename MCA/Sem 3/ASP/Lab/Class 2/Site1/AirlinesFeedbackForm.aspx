<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AirlinesFeedbackForm.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">    
    <title>Airlines feedback form</title>
    <link rel="stylesheet" href="~/Styles/custom.css" type="text/css" />
</head>
<body>
    <form id="form1" runat="server" method="post">
        <div>
            <div class="heading">Airlines Service Feedback</div>
            
            <div class="sub-heading">Choose an airline company:</div>
            <asp:ListBox ID="ListBox_AirlinesCompany" runat="server" Height="39px">
                <asp:ListItem>Lufthansa</asp:ListItem>
                <asp:ListItem>SpiceJet</asp:ListItem>
                <asp:ListItem>Air India</asp:ListItem>
                <asp:ListItem>Kingfisher</asp:ListItem>
                <asp:ListItem>British Airways</asp:ListItem>
            </asp:ListBox>
            
            <div class="sub-heading">Grading options:</div>
            <asp:RadioButtonList ID="RadioButtonList_Grading" runat="server">
                <asp:ListItem>Fair</asp:ListItem>
                <asp:ListItem>Good</asp:ListItem>
                <asp:ListItem>Excellent</asp:ListItem>
            </asp:RadioButtonList>
            
            <asp:Button ID="Button_Submit" runat="server" Text="Submit" 
                onclick="Button_Submit_Click" />
        </div>
        <div>
            <asp:TextBox ID="TextBox_SubmittedData" runat="server" CssClass="result"
                TextMode="MultiLine" ReadOnly="True" Visible="False"></asp:TextBox>
        </div>
    </form>
</body>
</html>

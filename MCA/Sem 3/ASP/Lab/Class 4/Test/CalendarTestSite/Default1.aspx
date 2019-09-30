<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default1.aspx.cs" Inherits="Calendar1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>[Test] Calendar 1</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Calendar ID="Calendar_Test" runat="server" 
                ondayrender="Calendar_Test_DayRender" 
                onselectionchanged="Calendar_Test_SelectionChanged" 
                onvisiblemonthchanged="Calendar_Test_VisibleMonthChanged"></asp:Calendar>
            <br>
            <asp:Button ID="Button1" runat="server" Text="Button" onclick="Button1_Click" />
        </div>
    </form>
</body>
</html>

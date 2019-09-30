<%@ Page Language="C#" AutoEventWireup="true" CodeFile="CalendarTest.aspx.cs" Inherits="CalendarTest" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" DefaultButton="Button_Submit" runat="server">
		<div>
			<asp:Calendar ID="Calendar1" runat="server"
				OnVisibleMonthChanged="Calendar1_VisibleMonthChanged"
				OnDayRender="Calendar1_DayRender"
				OnSelectionChanged="calender1_SelectionChanged">
			</asp:Calendar>
			<asp:Label ID="Label1" runat="server" Text=""></asp:Label>
		</div>
	<asp:TextBox ID="TextBox1" placeholder="txt1" runat="server" 
			AutoPostBack="true" ontextchanged="TextBox1_TextChanged"></asp:TextBox>
	<asp:TextBox ID="TextBox2" placeholder="txt2" runat="server" AutoPostBack="false"></asp:TextBox>
	<div>
		<fieldset>
			<legend>Upload files</legend>
			<asp:FileUpload ID="FileUpload1" runat="server" /> <br>
			<asp:FileUpload ID="FileUpload2" runat="server" /> <br>
			<asp:FileUpload ID="FileUpload3" runat="server" />
		</fieldset>
	</div>
	<div>
		<asp:Button ID="Button_Submit" runat="server" Text="Button" 
			onclick="Button_Submit_Click" oncommand="Button_Submit_Command" />
	</div>
    </form>
</body>
</html>

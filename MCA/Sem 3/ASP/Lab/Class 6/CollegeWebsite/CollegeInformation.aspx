<%@ Page Language="C#" AutoEventWireup="true" CodeFile="CollegeInformation.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>College Information</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
		<div>
			<asp:Menu ID="Menu_Main" runat="server" Orientation="Horizontal" 
				onmenuitemclick="Menu_Main_MenuItemClick"
				StaticMenuItemStyle-CssClass="tab"
				StaticSelectedStyle-CssClass="selected_tab"
				CssClass="tabs" >
				<Items>
					<asp:MenuItem Text="Home" Value="0" Selected="True"></asp:MenuItem>					
					<asp:MenuItem Text="Academics" Value="1"></asp:MenuItem>
					<asp:MenuItem Text="Admissions" Value="2"></asp:MenuItem>
					<asp:MenuItem Text="About Us" Value="3"></asp:MenuItem>
				</Items>
			</asp:Menu>
		</div>
		<div class="contents">
			<asp:MultiView ID="MultiView_CollegeInfo" runat="server" ActiveViewIndex="0">
				<asp:View ID="View_Home" runat="server">
					<h3>This is the college home page.</h3>
				</asp:View>
				<asp:View ID="View_Academics" runat="server">
					<h3>This is the college academics page.</h3>
				</asp:View>
				<asp:View ID="View_Admissions" runat="server">
					<h3>This is the college admissions page.</h3>
				</asp:View>
				<asp:View ID="View_AboutUs" runat="server">
					<h3>This is the college about us page.</h3>
				</asp:View>
			</asp:MultiView>
		</div>
    </form>
</body>
</html>

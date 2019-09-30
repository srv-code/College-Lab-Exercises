<%@ Page Language="C#" AutoEventWireup="true" CodeFile="RegistrationData.aspx.cs" Inherits="RegistrationDetails" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Registration Data</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">		
		<asp:SqlDataSource ID="SqlDataSource_Student" runat="server" 
			ConnectionString="<%$ ConnectionStrings:constr_locdb %>" 
			SelectCommand="SELECT * FROM [students]"></asp:SqlDataSource>
		<div class="header">Registration Data</div>
        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/RegistrationForm.aspx">Go to form</asp:HyperLink>
		<div>
			<asp:GridView ID="GridView_Registration" runat="server" 
				AutoGenerateColumns="False" DataKeyNames="id" 
				DataSourceID="SqlDataSource_Student">
				<Columns>
					<asp:BoundField DataField="id" HeaderText="id" InsertVisible="False" 
						ReadOnly="True" SortExpression="id" />
					<asp:BoundField DataField="name" HeaderText="name" SortExpression="name" />
					<asp:BoundField DataField="gender" HeaderText="gender" 
						SortExpression="gender" />
					<asp:BoundField DataField="dob" HeaderText="dob" SortExpression="dob" 
						 DataFormatString="{0:dd/MM/yyyy}" />
					<asp:BoundField DataField="address" HeaderText="address" 
						SortExpression="address" />
					<asp:BoundField DataField="marks_10" HeaderText="marks_10" 
						SortExpression="marks_10" />
					<asp:BoundField DataField="marks_12" HeaderText="marks_12" 
						SortExpression="marks_12" />
					<asp:BoundField DataField="grade_ug" HeaderText="grade_ug" 
						SortExpression="grade_ug" />
					<asp:BoundField DataField="grade_pg" HeaderText="grade_pg" 
						SortExpression="grade_pg" />
					<asp:BoundField DataField="achievement" HeaderText="achievement" 
						SortExpression="achievement" />
					<asp:BoundField DataField="reference1" HeaderText="reference1" 
						SortExpression="reference1" />
					<asp:BoundField DataField="reference2" HeaderText="reference2" 
						SortExpression="reference2" />
					<asp:BoundField DataField="reference3" HeaderText="reference3" 
						SortExpression="reference3" />
				</Columns>
			</asp:GridView>
		</div>
    </form>
</body>
</html>

<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Loans.aspx.cs" Inherits="Loans" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Loan information</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
    	<div>
			<asp:Menu ID="Menu_PageNavigation" runat="server" BackColor="#B5C7DE" 
				DynamicHorizontalOffset="2" Font-Names="Verdana" Font-Size="Small" 
				ForeColor="#284E98" onmenuitemclick="Menu_PageNavigation_MenuItemClick" 
				Orientation="Horizontal" StaticSubMenuIndent="10px">
				<DynamicHoverStyle BackColor="#284E98" ForeColor="White" />
				<DynamicMenuItemStyle HorizontalPadding="5px" VerticalPadding="2px" />
				<DynamicMenuStyle BackColor="#B5C7DE" />
				<DynamicSelectedStyle BackColor="#507CD1" />
				<Items>
					<asp:MenuItem Text="Customers" Value="Customers"></asp:MenuItem>
					<asp:MenuItem Selected="True" Text="Loans" Value="Loans"></asp:MenuItem>
					<asp:MenuItem Text="Information" Value="Information"></asp:MenuItem>
				</Items>
				<StaticHoverStyle BackColor="#284E98" ForeColor="White" />
				<StaticMenuItemStyle HorizontalPadding="5px" VerticalPadding="2px" />
				<StaticSelectedStyle BackColor="#507CD1" />
			</asp:Menu>
		</div>
		<div>
			<fieldset>
				<legend>Sorted & paged loan records</legend>

				<asp:ObjectDataSource ID="ObjectDataSource_SortedPagedLoanInfo" runat="server"
					 EnablePaging="true" SortParameterName="sortExpression"
					 TypeName="DbOperations.LoanData" SelectMethod="GetPagedSortedRecords" 
					 SelectCountMethod="GetRecordCount">
				</asp:ObjectDataSource>

				<asp:GridView ID="GridView_SortedPagedLoanInfo" runat="server"
					 DataSourceID="ObjectDataSource_SortedPagedLoanInfo"
					 AllowPaging="true" AllowSorting="true" PageSize="3">
				</asp:GridView>
			</fieldset>
		</div>
    </form>
</body>
</html>

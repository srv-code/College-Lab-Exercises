<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Details.aspx.cs" Inherits="Details" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Details</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
		<div>
			<h1>Details Page</h1>

			<asp:HyperLink ID="HyperLink1" runat="server"
				NavigateUrl="~/PhotoGallery.aspx">Go back to photo gallery</asp:HyperLink>

			<br/><br/><br/>

			<asp:DetailsView ID="DetailsView_Image" runat="server" AutoGenerateRows="False" 
				DataKeyNames="id" DataSourceID="SqlDataSource_Images">
				<Fields>
					<asp:BoundField DataField="name" HeaderText="Name" SortExpression="name" />
					<asp:TemplateField HeaderText="Image" SortExpression="storage_path">
						<EditItemTemplate>
							<asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("storage_path") %>'></asp:TextBox>
						</EditItemTemplate>
						<InsertItemTemplate>
							<asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("storage_path") %>'></asp:TextBox>
						</InsertItemTemplate>
						<ItemTemplate>
							<asp:Image ID="Image1" runat="server" AlternateText='<%# Eval("name") %>' 
								ImageUrl='<%# Eval("storage_path") %>' />
						</ItemTemplate>
					</asp:TemplateField>
					<asp:TemplateField HeaderText="Description" SortExpression="description">
						<EditItemTemplate>
							<asp:TextBox ID="TextBox2" runat="server" Text='<%# Bind("description") %>'></asp:TextBox>
						</EditItemTemplate>
						<InsertItemTemplate>
							<asp:TextBox ID="TextBox2" runat="server" Text='<%# Bind("description") %>'></asp:TextBox>
						</InsertItemTemplate>
						<ItemTemplate>
							<asp:TextBox ID="TextBox3" runat="server" TextMode="MultiLine" ReadOnly="True" CssClass="desc" Text='<%# Bind("description") %>'></asp:TextBox>
						</ItemTemplate>
					</asp:TemplateField>
				</Fields>
			</asp:DetailsView>
			<asp:SqlDataSource ID="SqlDataSource_Images" runat="server" 
				ConnectionString="<%$ ConnectionStrings:localdb %>" 
				SelectCommand="SELECT * FROM [images] WHERE ([id] = @id)">
				<SelectParameters>
					<asp:QueryStringParameter DefaultValue="1" Name="id" QueryStringField="id" 
						Type="Int32" />
				</SelectParameters>
			</asp:SqlDataSource>
		</div>
    </form>
</body>
</html>

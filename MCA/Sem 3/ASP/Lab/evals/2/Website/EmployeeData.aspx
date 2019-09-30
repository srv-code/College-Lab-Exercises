<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EmployeeData.aspx.cs" Inherits="EmployeeData" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server" enctype="multipart/form-data">
		<div>
			<asp:SqlDataSource ID="SqlDataSource_Employee" runat="server" 
				ConflictDetection="CompareAllValues" 
				ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
				DeleteCommand="DELETE FROM [employee] WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([pic] = @original_pic) OR ([pic] IS NULL AND @original_pic IS NULL)) AND (([city] = @original_city) OR ([city] IS NULL AND @original_city IS NULL))" 
				InsertCommand="INSERT INTO [employee] ([name], [pic], [city]) VALUES (@name, @pic, @city)" 
				OldValuesParameterFormatString="original_{0}" 
				SelectCommand="SELECT * FROM [employee]" 
				
				UpdateCommand="UPDATE [employee] SET [name] = @name, [pic] = @pic, [city] = @city WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([pic] = @original_pic) OR ([pic] IS NULL AND @original_pic IS NULL)) AND (([city] = @original_city) OR ([city] IS NULL AND @original_city IS NULL))" 
				oninserting="SqlDataSource_Employee_Inserting">
				<DeleteParameters>
					<asp:Parameter Name="original_id" Type="Int32" />
					<asp:Parameter Name="original_name" Type="String" />
					<asp:Parameter Name="original_pic" Type="String" />
					<asp:Parameter Name="original_city" Type="String" />
				</DeleteParameters>
				<InsertParameters>
					<asp:Parameter Name="name" Type="String" />
					<asp:Parameter Name="pic" Type="String" />
					<asp:Parameter Name="city" Type="String" />
				</InsertParameters>
				<UpdateParameters>
					<asp:Parameter Name="name" Type="String" />
					<asp:Parameter Name="pic" Type="String" />
					<asp:Parameter Name="city" Type="String" />
					<asp:Parameter Name="original_id" Type="Int32" />
					<asp:Parameter Name="original_name" Type="String" />
					<asp:Parameter Name="original_pic" Type="String" />
					<asp:Parameter Name="original_city" Type="String" />
				</UpdateParameters>
			</asp:SqlDataSource>

			<div>
				<h3>Employee details:</h3>
				<asp:GridView ID="GridView_Employee" runat="server" AutoGenerateColumns="False" 
					DataKeyNames="id" DataSourceID="SqlDataSource_Employee">
					<Columns>
						<asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
						<asp:BoundField DataField="id" HeaderText="id" InsertVisible="False" 
							ReadOnly="True" SortExpression="id" />
						<asp:TemplateField HeaderText="pic" SortExpression="pic">
							<EditItemTemplate>
								<asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("pic") %>' Height="20" Width="20" />
							</EditItemTemplate>
							<ItemTemplate>
								<asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("pic") %>' Height="20" Width="20" />
							</ItemTemplate>
						</asp:TemplateField>
						<asp:BoundField DataField="name" HeaderText="name" SortExpression="name" />
						<asp:TemplateField HeaderText="city" SortExpression="city">
							<EditItemTemplate>
								<asp:LinkButton ID="LinkButton1" runat="server" 
									PostBackUrl='<%# Eval("city", "City.aspx?name={0}") %>' 
									Text='<%# Eval("city") %>'></asp:LinkButton>
							</EditItemTemplate>
							<ItemTemplate>
								<asp:LinkButton ID="LinkButton1" runat="server" 
									PostBackUrl='<%# Eval("city", "City.aspx?name={0}") %>' 
									Text='<%# Eval("city") %>'></asp:LinkButton>
							</ItemTemplate>
						</asp:TemplateField>
					</Columns>
					<EmptyDataTemplate>
						<asp:Label ID="Label1" runat="server" Text="No data found!"></asp:Label>
					</EmptyDataTemplate>
				</asp:GridView>
			</div>

			<div>
				<h3>New:</h3>
				<asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
					DataKeyNames="id" DataSourceID="SqlDataSource_Employee">
					<Columns>
						<asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
						<asp:BoundField DataField="id" HeaderText="id" InsertVisible="False" 
							ReadOnly="True" SortExpression="id" />
						<asp:BoundField DataField="name" HeaderText="name" SortExpression="name" />
						<asp:BoundField DataField="pic" HeaderText="pic" SortExpression="pic" />
						<asp:BoundField DataField="city" HeaderText="city" SortExpression="city" />
					</Columns>
				</asp:GridView>
			</div>

			<div>
			<h3>Add new employee details:</h3>
				<asp:DetailsView ID="DetailsView1" runat="server" Height="50px" Width="125px" 
					AutoGenerateRows="False" DataKeyNames="id" 
					DataSourceID="SqlDataSource_Employee" oniteminserting="DetailsView1_ItemInserting">
					<Fields>
						<asp:BoundField DataField="name" HeaderText="name" SortExpression="name" />
						<asp:TemplateField HeaderText="pic" SortExpression="pic">
							<EditItemTemplate>
								<asp:FileUpload ID="FileUpload1" runat="server" />
							</EditItemTemplate>
							<InsertItemTemplate>
								<asp:FileUpload ID="FileUpload1_1" runat="server" />
							</InsertItemTemplate>
							<ItemTemplate>
								<asp:Image ID="Image2" runat="server" ImageUrl='<%# Eval("pic") %>' />
							</ItemTemplate>
						</asp:TemplateField>
						<asp:BoundField DataField="city" HeaderText="city" SortExpression="city" />
						<asp:CommandField ShowInsertButton="True" />
					</Fields>
				</asp:DetailsView>
			</div>
		</div>
    </form>
</body>
</html>

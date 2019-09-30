<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EmployeeDetails.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Employee details</title>
</head>
<body>
    <form id="form1" runat="server">
		<div>
            <asp:Label ID="Label_OperationStatus" runat="server"></asp:Label>
			<asp:ValidationSummary ID="ValidationSummary1" runat="server"
				ValidationGroup="new_record" ShowMessageBox="True" 
				ShowSummary="False" HeaderText="Error in new employee details" />
        </div>
        <div>
            <asp:GridView ID="GridView_EmpLoc" runat="server" 
                AllowSorting="True" AutoGenerateColumns="False" DataKeyNames="id" 
                DataSourceID="SqlDataSource_Employees" ShowFooter="True" 
                onrowcommand="GridView1_RowCommand" AllowPaging="True">
                <Columns>
                    <asp:TemplateField ShowHeader="False">
						<EditItemTemplate>
							<asp:ImageButton ID="ImageButton_Update" runat="server" CausesValidation="True" 
								ImageUrl="~/Images/icons/update.png" Height="20" Width="20" ToolTip="Update record" 
                                AlternateText="Update" CommandName="Update" Text="Update">
							</asp:ImageButton>
                            &nbsp;
							<asp:ImageButton ID="ImageButton_Cancel" runat="server" CausesValidation="False" 
								ImageUrl="~/Images/icons/cancel.png" Height="20" Width="20" ToolTip="Cancel editing record" 
                                AlternateText="Cancel" CommandName="Cancel" Text="Cancel">
							</asp:ImageButton>
						</EditItemTemplate>
						<FooterTemplate>
							<asp:ImageButton ID="ImageButton_AddNew" runat="server" ValidationGroup="new_record"
								AlternateText="Add" ImageUrl="~/Images/icons/add.png" Height="20" Width="20" 
								ToolTip="Add new record" Text="Add">
							</asp:ImageButton>
						</FooterTemplate>
						<ItemTemplate>
							<asp:ImageButton ID="ImageButton_Edit" runat="server" CausesValidation="False" 
								ImageUrl="~/Images/icons/edit.png" Height="20" Width="20" ToolTip="Edit record"
                                AlternateText="Edit" CommandName="Edit" Text="Edit">
							</asp:ImageButton>
                            &nbsp;
							<asp:ImageButton ID="ImageButton_Delete" runat="server" CausesValidation="False" 
								ImageUrl="~/Images/icons/delete.png" Height="20" Width="20" ToolTip="Delete record"
                                AlternateText="Delete" CommandName="Delete" Text="Delete">
							</asp:ImageButton>
						</ItemTemplate>
					</asp:TemplateField>
					<asp:TemplateField HeaderText="id" InsertVisible="False" SortExpression="id">
						<EditItemTemplate>
							<asp:Label ID="Label1" runat="server" Text='<%# Eval("id") %>'></asp:Label>
						</EditItemTemplate>
						<ItemTemplate>
							<asp:Label ID="Label1" runat="server" Text='<%# Bind("id") %>'></asp:Label>
						</ItemTemplate>
					</asp:TemplateField>
					<asp:TemplateField HeaderText="name" SortExpression="name">
						<EditItemTemplate>
							<asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("name") %>'></asp:TextBox>
						</EditItemTemplate>
						<FooterTemplate>
							<asp:TextBox ID="TextBox_NewName" runat="server"></asp:TextBox>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator_NewName" runat="server" 
								ErrorMessage="Enter the name!" ValidationGroup="new_record"
								ControlToValidate="TextBox_NewName" Text="*" ForeColor="Red">
							</asp:RequiredFieldValidator>
						</FooterTemplate>
						<ItemTemplate>
							<asp:Label ID="Label2" runat="server" Text='<%# Bind("name") %>'></asp:Label>
						</ItemTemplate>
					</asp:TemplateField>
					<asp:TemplateField HeaderText="department" SortExpression="department">
						<EditItemTemplate>
							<asp:DropDownList ID="DropDownList1" runat="server" 
								DataSourceID="SqlDataSource_Departments" DataTextField="name" 
								DataValueField="name" AppendDataBoundItems="True" SelectedValue='<%# Bind("department") %>'>
							</asp:DropDownList>
						</EditItemTemplate>
						<FooterTemplate>
							<asp:DropDownList ID="DropDownList_NewDepartment" runat="server" AppendDataBoundItems="True" 
								DataSourceID="SqlDataSource_Departments" DataTextField="name" 
								DataValueField="name">
								<asp:ListItem>-- Select --</asp:ListItem>
							</asp:DropDownList>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator_NewDepartment" runat="server" 
								ErrorMessage="Enter the department!" ValidationGroup="new_record"
								ControlToValidate="DropDownList_NewDepartment" Text="*" ForeColor="Red"
								InitialValue="-- Select --">
							</asp:RequiredFieldValidator>
						</FooterTemplate>
						<ItemTemplate>
							<asp:Label ID="Label3" runat="server" Text='<%# Bind("department") %>'></asp:Label>
						</ItemTemplate>
					</asp:TemplateField>
					<asp:TemplateField HeaderText="designation" SortExpression="designation">
						<EditItemTemplate>
							<asp:TextBox ID="TextBox3" runat="server" Text='<%# Bind("designation") %>'></asp:TextBox>
						</EditItemTemplate>
						<FooterTemplate>
							<asp:TextBox ID="TextBox_NewDesignation" runat="server" 
								Text='<%# Bind("designation") %>'></asp:TextBox>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator_NewDesignation" runat="server" 
								ErrorMessage="Enter the designation!" ValidationGroup="new_record"
								ControlToValidate="TextBox_NewDesignation" Text="*" ForeColor="Red">
							</asp:RequiredFieldValidator>
						</FooterTemplate>
						<ItemTemplate>
							<asp:Label ID="Label4" runat="server" Text='<%# Bind("designation") %>'></asp:Label>
						</ItemTemplate>
					</asp:TemplateField>
                </Columns>
                <EmptyDataTemplate>
                    <asp:Label ID="Label1" runat="server" Text="No data found!" BackColor="Red" 
                        ForeColor="Yellow"></asp:Label>
                </EmptyDataTemplate>
            </asp:GridView>
        </div>
    <asp:SqlDataSource ID="SqlDataSource_Employees" runat="server" 
            ConflictDetection="CompareAllValues" 
            ConnectionString="<%$ ConnectionStrings:localdb %>" 
            DeleteCommand="DELETE FROM [employees] WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([department] = @original_department) OR ([department] IS NULL AND @original_department IS NULL)) AND (([designation] = @original_designation) OR ([designation] IS NULL AND @original_designation IS NULL))" 
            InsertCommand="INSERT INTO [employees] ([name], [department], [designation]) VALUES (@name, @department, @designation)" 
            OldValuesParameterFormatString="original_{0}" 
            SelectCommand="SELECT * FROM [employees]" 
            
			UpdateCommand="UPDATE [employees] SET [name] = @name, [department] = @department, [designation] = @designation WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([department] = @original_department) OR ([department] IS NULL AND @original_department IS NULL)) AND (([designation] = @original_designation) OR ([designation] IS NULL AND @original_designation IS NULL))">
        <DeleteParameters>
            <asp:Parameter Name="original_id" Type="Int32" />
            <asp:Parameter Name="original_name" Type="String" />
            <asp:Parameter Name="original_department" Type="String" />
            <asp:Parameter Name="original_designation" Type="String" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="department" Type="String" />
            <asp:Parameter Name="designation" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="department" Type="String" />
            <asp:Parameter Name="designation" Type="String" />
            <asp:Parameter Name="original_id" Type="Int32" />
            <asp:Parameter Name="original_name" Type="String" />
            <asp:Parameter Name="original_department" Type="String" />
            <asp:Parameter Name="original_designation" Type="String" />
        </UpdateParameters>
        </asp:SqlDataSource>
    <asp:SqlDataSource ID="SqlDataSource_Departments" runat="server" 
            ConnectionString="<%$ ConnectionStrings:localdb %>" 
            SelectCommand="SELECT * FROM [departments]"></asp:SqlDataSource>
    </form>
</body>
</html>

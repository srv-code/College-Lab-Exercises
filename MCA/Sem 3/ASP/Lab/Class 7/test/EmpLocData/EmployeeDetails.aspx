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
                onrowcommand="GridView1_RowCommand">
                <Columns>
                    <asp:TemplateField ShowHeader="False">
                        <EditItemTemplate>
							<asp:ImageButton ID="ImageButton_Update" runat="server" CausesValidation="True" 
								ImageUrl="~/Images/icons/update.png" Height="20" Width="20" ToolTip="Update record" 
                                CommandName="Update" Text="Update"></asp:ImageButton>
                            &nbsp;
							<asp:ImageButton ID="ImageButton_Cancel" runat="server" CausesValidation="False" 
								ImageUrl="~/Images/icons/cancel.png" Height="20" Width="20" ToolTip="Cancel editing record" 
                                CommandName="Cancel" Text="Cancel"></asp:ImageButton>
                            <%--<asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="True" 
                                CommandName="Update" Text="Update"></asp:LinkButton>
                            &nbsp;<asp:LinkButton ID="LinkButton2" runat="server" CausesValidation="False" 
                                CommandName="Cancel" Text="Cancel"></asp:LinkButton>--%>
                        </EditItemTemplate>
                        <FooterTemplate>
                            <%--<asp:LinkButton ID="LinkButton3" runat="server">Add</asp:LinkButton>--%>
                            <asp:ImageButton ID="ImageButton_AddNew" runat="server" ValidationGroup="new_record"
								ImageUrl="~/Images/icons/add.png" Height="20" Width="20" ToolTip="Add new record" Text="Add">
							</asp:ImageButton>
                        </FooterTemplate>
                        <ItemTemplate>
                            <asp:ImageButton ID="ImageButton_Edit" runat="server" CausesValidation="False" 
								ImageUrl="~/Images/icons/edit.png" Height="20" Width="20" ToolTip="Edit record"
                                CommandName="Edit" Text="Edit">
							</asp:ImageButton>
                            &nbsp;
							<asp:ImageButton ID="ImageButton_Delete" runat="server" CausesValidation="False" 
								ImageUrl="~/Images/icons/delete.png" Height="20" Width="20" ToolTip="Delete record"
                                CommandName="Delete" Text="Delete">
							</asp:ImageButton>
							<%--<asp:LinkButton ID="LinkButton3" runat="server" CausesValidation="False" 
                                CommandName="Edit" Text="Edit"></asp:LinkButton>
                            &nbsp;<asp:LinkButton ID="LinkButton4" runat="server" CausesValidation="False" 
                                CommandName="Delete" Text="Delete"></asp:LinkButton>--%>	
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
								Text="*" ControlToValidate="TextBox_NewName" ForeColor="Red"
								ErrorMessage="Enter a name!" ValidationGroup="new_record">
							</asp:RequiredFieldValidator>
                        </FooterTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label2" runat="server" Text='<%# Bind("name") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="location" SortExpression="location">
                        <EditItemTemplate>
                            <asp:DropDownList ID="DropDownList1" runat="server" 
                                DataSourceID="SqlDataSource_Locations" DataTextField="name" 
                                DataValueField="name" SelectedValue='<%# Bind("location") %>' 
                                AppendDataBoundItems="True">
                            </asp:DropDownList>
                        </EditItemTemplate>
                        <FooterTemplate>
                            <asp:DropDownList ID="DropDownList_NewLocation" runat="server" 
                                DataSourceID="SqlDataSource_Locations" DataTextField="name" 
                                DataValueField="name" AppendDataBoundItems="True">
                                <asp:ListItem>-- Select --</asp:ListItem>
                            </asp:DropDownList>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator_NewLocation" runat="server" 
								ControlToValidate="DropDownList_NewLocation" Text="*" InitialValue="-- Select --"
								ForeColor="Red" ErrorMessage="Choose a location!" ValidationGroup="new_record">
							</asp:RequiredFieldValidator>
                        </FooterTemplate>
                        <ItemTemplate>
                            <asp:Label ID="Label3" runat="server" Text='<%# Bind("location") %>'></asp:Label>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:TemplateField HeaderText="designation" SortExpression="designation">
                        <EditItemTemplate>
                            <asp:TextBox ID="TextBox3" runat="server" Text='<%# Bind("designation") %>'></asp:TextBox>
                        </EditItemTemplate>
                        <FooterTemplate>
                            <asp:TextBox ID="TextBox_NewDesignation" runat="server"></asp:TextBox>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator_NewDesignation" runat="server" 
								ErrorMessage="Enter a designation!" Text="*" ForeColor="Red"
								ControlToValidate="TextBox_NewDesignation" ValidationGroup="new_record">
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
            DeleteCommand="DELETE FROM [employees] WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([location] = @original_location) OR ([location] IS NULL AND @original_location IS NULL)) AND (([designation] = @original_designation) OR ([designation] IS NULL AND @original_designation IS NULL))" 
            InsertCommand="INSERT INTO [employees] ([name], [location], [designation]) VALUES (@name, @location, @designation)" 
            OldValuesParameterFormatString="original_{0}" 
            SelectCommand="SELECT * FROM [employees]" 
            UpdateCommand="UPDATE [employees] SET [name] = @name, [location] = @location, [designation] = @designation WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([location] = @original_location) OR ([location] IS NULL AND @original_location IS NULL)) AND (([designation] = @original_designation) OR ([designation] IS NULL AND @original_designation IS NULL))">
        <DeleteParameters>
            <asp:Parameter Name="original_id" Type="Int32" />
            <asp:Parameter Name="original_name" Type="String" />
            <asp:Parameter Name="original_location" Type="String" />
            <asp:Parameter Name="original_designation" Type="String" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="location" Type="String" />
            <asp:Parameter Name="designation" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="location" Type="String" />
            <asp:Parameter Name="designation" Type="String" />
            <asp:Parameter Name="original_id" Type="Int32" />
            <asp:Parameter Name="original_name" Type="String" />
            <asp:Parameter Name="original_location" Type="String" />
            <asp:Parameter Name="original_designation" Type="String" />
        </UpdateParameters>
        </asp:SqlDataSource>
    <asp:SqlDataSource ID="SqlDataSource_Locations" runat="server" 
            ConnectionString="<%$ ConnectionStrings:localdb %>" 
            SelectCommand="SELECT * FROM [locations]"></asp:SqlDataSource>
    </form>
</body>
</html>

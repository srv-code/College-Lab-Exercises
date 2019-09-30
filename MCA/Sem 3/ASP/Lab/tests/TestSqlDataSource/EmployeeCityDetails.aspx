<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EmployeeCityDetails.aspx.cs" Inherits="EmployeeCityDetails" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            
        </div>
		<div>
			<asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
				DataKeyNames="userid,username" DataSourceID="SqlDataSource_emp" ShowFooter="True" 
				onrowcommand="GridView1_RowCommand">
				<Columns>
					<asp:BoundField DataField="userid" HeaderText="userid" InsertVisible="False" 
						ReadOnly="True" SortExpression="userid" />
					<asp:BoundField DataField="username" HeaderText="username" ReadOnly="True" 
                        SortExpression="username" />
                    <asp:BoundField DataField="city" HeaderText="city" SortExpression="city" />
                    <asp:BoundField DataField="designation" HeaderText="designation" 
                        SortExpression="designation" />
				</Columns>
			</asp:GridView>

			<!-- Data Sources -->
			<asp:SqlDataSource ID="SqlDataSource_emp" runat="server" ConflictDetection="CompareAllValues"
				ConnectionString="<%$ ConnectionStrings:constr_locdb %>" DeleteCommand="DELETE FROM [emp_details] WHERE [userid] = @original_userid AND [username] = @original_username AND (([city] = @original_city) OR ([city] IS NULL AND @original_city IS NULL)) AND (([designation] = @original_designation) OR ([designation] IS NULL AND @original_designation IS NULL))"
				InsertCommand="INSERT INTO [emp_details] ([username], [city], [designation]) VALUES (@username, @city, @designation)"
				OldValuesParameterFormatString="original_{0}" SelectCommand="SELECT * FROM [emp_details]"
				UpdateCommand="UPDATE [emp_details] SET [city] = @city, [designation] = @designation WHERE [userid] = @original_userid AND [username] = @original_username AND (([city] = @original_city) OR ([city] IS NULL AND @original_city IS NULL)) AND (([designation] = @original_designation) OR ([designation] IS NULL AND @original_designation IS NULL))">
				<DeleteParameters>
					<asp:Parameter Name="original_userid" Type="Int32" />
					<asp:Parameter Name="original_username" Type="String" />
					<asp:Parameter Name="original_city" Type="String" />
					<asp:Parameter Name="original_designation" Type="String" />
				</DeleteParameters>
				<InsertParameters>
					<asp:Parameter Name="username" Type="String" />
					<asp:Parameter Name="city" Type="String" />
					<asp:Parameter Name="designation" Type="String" />
				</InsertParameters>
				<UpdateParameters>
					<asp:Parameter Name="city" Type="String" />
					<asp:Parameter Name="designation" Type="String" />
					<asp:Parameter Name="original_userid" Type="Int32" />
					<asp:Parameter Name="original_username" Type="String" />
					<asp:Parameter Name="original_city" Type="String" />
					<asp:Parameter Name="original_designation" Type="String" />
				</UpdateParameters>
			</asp:SqlDataSource>
			<asp:SqlDataSource ID="SqlDataSource_city" runat="server" 
				ConnectionString="<%$ ConnectionStrings:constr_locdb %>" 
				SelectCommand="SELECT * FROM [city_details]">
			</asp:SqlDataSource>
		</div>
    </form>
</body>
</html>

<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Comments.aspx.cs" Inherits="Comments" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Comments</title>
	<style type="text/css">
		fieldset {
			padding: 10px;
		}
		
		.comment {
			padding: 5px;
			border: dotted 2px black;
			margin: 10px;
		}
		
		.tdd {
			margin: 10px;
			padding: 5px;
			width:255px;
		}
	</style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
		<asp:SqlDataSource ID="SqlDataSource1" runat="server" 
			ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
			SelectCommand="SELECT * FROM [Imageupdis]">
		</asp:SqlDataSource>
		
		<asp:SqlDataSource ID="SqlDataSource2" runat="server" 
			ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
			InsertCommand="INSERT INTO [imagecomment] ([iname], [comment],[ename]) 
							VALUES (@iname, @comment,@ename)" 
			SelectCommand="SELECT i.comment,i.ename,e.epath 
							FROM imagecomment i inner join emppp e on i.ename=e.ename 
							WHERE i.iname = @iiname">
			<InsertParameters>
				<asp:Parameter Name="iname" Type="String" />
				<asp:Parameter Name="comment" Type="String" />
				<asp:Parameter Name="ename" Type="String" />
			</InsertParameters>
			<SelectParameters>
				<asp:SessionParameter Name="iiname" SessionField="Iname" Type="String" />
				<%-- <asp:SessionParameter Name="einame" SessionField="ename" Type="String" /> --%>
			</SelectParameters>
		</asp:SqlDataSource>
		
		<asp:FormView ID="FormView1" runat="server"
				AllowPaging="True" DataKeyNames="ImageName"
				DataSourceID="SqlDataSource1"
				ondatabound="FormView1_DataBound">
			<ItemTemplate>
				<fieldset>
					<legend>Comment on the image</legend>
					<table border="1" >
						<tr>
							<td> 
								<asp:Image ID="Image1" runat="server" 
									ImageUrl='<%# Eval("ImagePath") %>' 
									Height="300px" Width="330px" />
							</td>
						</tr>
					</table>
					<asp:ListView ID="ListView1" runat="server" 
							ItemPlaceholderID="itemplaceholder"
							InsertItemPosition="FirstItem" Visible="false" >
						<LayoutTemplate>
							<asp:PlaceHolder ID="itemplaceholder" runat="server"/>
						</LayoutTemplate>
						<EmptyDataTemplate>No Data</EmptyDataTemplate>

						<ItemTemplate>
							<table>
								<tr>
									<td class="tdd">
										<%# Eval("comment") %>
									</td>
									<td>
										<asp:Image ID="Image3" runat="server" 
											ImageUrl='<%# Eval("epath") %>' 
											Height="60px" Width="50px" />
									</td>
								</tr>
							</table>
						</ItemTemplate>
			
						<InsertItemTemplate>
							<table border="1">
								<tr>
									<td>
										<asp:TextBox id="txtComment" Runat="server" 
											AutoPostBack="true" 
											ontextchanged="txtComment_TextChanged" 
											Width="310px" Height="60px" />
									</td>
								</tr>
							</table>        
						</InsertItemTemplate>
					</asp:ListView>
				</fieldset>
			</ItemTemplate>
			<PagerSettings Position="Top" Mode="Numeric" />
		</asp:FormView>
    </div>
    </form>
</body>
</html>

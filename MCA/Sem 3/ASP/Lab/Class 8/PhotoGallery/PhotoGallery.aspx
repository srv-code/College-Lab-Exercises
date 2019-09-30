<%@ Page Language="C#" AutoEventWireup="true" CodeFile="PhotoGallery.aspx.cs" Inherits="TeachersDayCelebration" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Teachers' Photo Gallery</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
		<div>			
			<h1>Happy Teachers' Day</h1>

			<div>				
				<h2>Add a new photo</h2>
				<asp:ValidationSummary ID="ValidationSummary1" HeaderText="Error in upload form!" ShowMessageBox="true" ShowSummary="false" ValidationGroup="img_upload" runat="server" />
				<asp:Label ID="Label_UploadError" ForeColor="Red" runat="server"></asp:Label>
				<table>
					<tr>
						<td>Name</td>
						<td>
							<asp:TextBox ID="TextBox_NewName" runat="server"></asp:TextBox>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="Enter name" Text="*" Display="Dynamic" ForeColor="Red" SetFocusOnError="true" ControlToValidate="TextBox_NewName" ValidationGroup="img_upload"></asp:RequiredFieldValidator>
						</td>
					</tr>
					<tr>
						<td>Description</td>
						<td>
							<asp:TextBox ID="TextBox_NewDescription" TextMode="MultiLine" runat="server"></asp:TextBox>
							<asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="Enter description" Text="*" Display="Dynamic" ForeColor="Red" SetFocusOnError="true" ControlToValidate="TextBox_NewDescription" ValidationGroup="img_upload"></asp:RequiredFieldValidator>
						</td>
					</tr>
					<tr>
						<td>Photo</td>
						<td>
							<asp:FileUpload ID="FileUpload_NewPhoto" runat="server" />
							<asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ErrorMessage="Select a photo" Text="*" Display="Dynamic" ForeColor="Red" SetFocusOnError="true" ControlToValidate="FileUpload_NewPhoto" ValidationGroup="img_upload"></asp:RequiredFieldValidator>
						</td>
					</tr>
					<tr>
						<td>
							<asp:Button ID="Button_Upload" runat="server" Text="Upload" 
								CausesValidation="true" ValidationGroup="img_upload" 
								onclick="Button_Upload_Click" />
						</td>
						<td>
							<asp:Button ID="Button_Cancel" runat="server" Text="Cancel" 
								CausesValidation="false" ValidationGroup="img_upload" 
								onclick="Button_Cancel_Click" />
						</td>
					</tr>
				</table>
			</div>

			<div>
				<h2>Photo gallery</h2>
				<asp:GridView ID="GridView_Images" runat="server" AutoGenerateColumns="False" 
					DataKeyNames="id" DataSourceID="SqlDataSource_Images" ShowHeader="False">
					<Columns>						
						<asp:BoundField DataField="name" HeaderText="Name" SortExpression="name" />
						<asp:TemplateField HeaderText="id" InsertVisible="False" SortExpression="id">
							<EditItemTemplate>
								<asp:Label ID="Label1" runat="server" Text='<%# Eval("id") %>'></asp:Label>
							</EditItemTemplate>
							<ItemTemplate>
								<asp:ImageButton ID="ImageButton1" runat="server" 
									AlternateText='<%# Eval("name") %>' CssClass="img_small" 
									ImageUrl='<%# Eval("storage_path") %>' 
									PostBackUrl='<%# Eval("id", "Details.aspx?id={0}") %>' />
							</ItemTemplate>
						</asp:TemplateField>
					</Columns>
				</asp:GridView>
			</div>
				
		</div>
    	<asp:SqlDataSource ID="SqlDataSource_Images" runat="server" 
			ConnectionString="<%$ ConnectionStrings:localdb %>" 
			SelectCommand="SELECT * FROM [images]" ConflictDetection="CompareAllValues" 
			DeleteCommand="DELETE FROM [images] WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([storage_path] = @original_storage_path) OR ([storage_path] IS NULL AND @original_storage_path IS NULL)) AND (([description] = @original_description) OR ([description] IS NULL AND @original_description IS NULL))" 
			InsertCommand="INSERT INTO [images] ([name], [storage_path], [description]) VALUES (@name, @storage_path, @description)" 
			OldValuesParameterFormatString="original_{0}" 
			UpdateCommand="UPDATE [images] SET [name] = @name, [storage_path] = @storage_path, [description] = @description WHERE [id] = @original_id AND (([name] = @original_name) OR ([name] IS NULL AND @original_name IS NULL)) AND (([storage_path] = @original_storage_path) OR ([storage_path] IS NULL AND @original_storage_path IS NULL)) AND (([description] = @original_description) OR ([description] IS NULL AND @original_description IS NULL))">
			<DeleteParameters>
				<asp:Parameter Name="original_id" Type="Int32" />
				<asp:Parameter Name="original_name" Type="String" />
				<asp:Parameter Name="original_storage_path" Type="String" />
				<asp:Parameter Name="original_description" Type="String" />
			</DeleteParameters>
			<InsertParameters>
				<asp:Parameter Name="name" Type="String" />
				<asp:Parameter Name="storage_path" Type="String" />
				<asp:Parameter Name="description" Type="String" />
			</InsertParameters>
			<UpdateParameters>
				<asp:Parameter Name="name" Type="String" />
				<asp:Parameter Name="storage_path" Type="String" />
				<asp:Parameter Name="description" Type="String" />
				<asp:Parameter Name="original_id" Type="Int32" />
				<asp:Parameter Name="original_name" Type="String" />
				<asp:Parameter Name="original_storage_path" Type="String" />
				<asp:Parameter Name="original_description" Type="String" />
			</UpdateParameters>
		</asp:SqlDataSource>
    </form>
</body>
</html>

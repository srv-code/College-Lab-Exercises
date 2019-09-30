<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
		<div>
			<asp:ValidationSummary ID="ValidationSummary1" runat="server" ValidationGroup="cd" />
			<h1>Contact Details</h1>
			<table>
				<tr>
					<td>Name</td>
					<td>
						<asp:TextBox ID="TextBox_Name" runat="server"></asp:TextBox>
                        <asp:RegularExpressionValidator ID="RegularExpressionValidator_Name" runat="server"
                            SetFocusOnError="True"
                            CssClass="invalid"
                            Display="Dynamic"
                            ControlToValidate="TextBox_Name"
                            Text="!"
                            ErrorMessage="Invalid name" 
                            ValidationExpression="^[A-Z][a-z]*$" ValidationGroup="cd"></asp:RegularExpressionValidator>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                            SetFocusOnError="True"
                            CssClass="invalid"
                            Display="Dynamic"
                            Text="*"
                            ControlToValidate="TextBox_Name"
                            ErrorMessage="Name required" ValidationGroup="cd"></asp:RequiredFieldValidator>
					</td>
				</tr>
				<tr>
                    <td>Phone number</td>
                    <td>
                        <asp:TextBox ID="TextBox_Phone" runat="server"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" 
                            SetFocusOnError="True"
                            CssClass="invalid"
                            Display="Dynamic"
                            ControlToValidate="TextBox_Phone"
                            Text="*"
                            ErrorMessage="Phone number required" ValidationGroup="cd">
                        </asp:RequiredFieldValidator>
                        <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                            SetFocusOnError="True"
                            CssClass="invalid"
                            Display="Dynamic"
                            ControlToValidate="TextBox_Phone"
                            Text="!"
                            ValidationExpression="^\d{10}$"
                            ErrorMessage="Phone number invalid" ValidationGroup="cd"></asp:RegularExpressionValidator>
                    </td>
                </tr>
				<tr>
					<td>Email ID</td>
					<td>
						<asp:TextBox ID="TextBox_Email" runat="server"></asp:TextBox>
						<asp:RegularExpressionValidator ID="RegularExpressionValidator4" runat="server" 
							SetFocusOnError="True"
							CssClass="invalid"
							Display="Dynamic"
							Text="!"                                    
							ErrorMessage="Invalid Email ID" 
							ControlToValidate="TextBox_Email"
							ValidationExpression="^(\w+[+.]*)+@manipal.edu$" ValidationGroup="cd">
						</asp:RegularExpressionValidator>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
							SetFocusOnError="True"
							CssClass="invalid"
							Display="Dynamic"
							ControlToValidate="TextBox_Email"
							Text="*"
							ErrorMessage="Email ID required" ValidationGroup="cd">
						</asp:RequiredFieldValidator>
					</td>
				</tr>
					<tr>
                            <td>
                                <asp:Button ID="Button_ContSubmit" runat="server" Text="Submit" 
									ValidationGroup="cd" onclick="Button_ContSubmit_Click" />
                            </td>
                            <td>
                                <asp:Button ID="Button_ContCancel" CausesValidation=false runat="server" 
									Text="Cancel" onclick="Button_ContCancel_Click" style="height: 26px" />
                            </td>
                        </tr>
			</table>
		</div>
    
		<div>
			<asp:ValidationSummary ID="ValidationSummary2" runat="server" ValidationGroup="sd" />
			<h1>Subscriber's Details</h1>
			 <table>
				<tr>
					<td>Username</td>
					<td>
                                <asp:TextBox ID="TextBox_Username" runat="server"></asp:TextBox>
                                <asp:RegularExpressionValidator ID="RegularExpressionValidator2" runat="server"
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_Username"
                                    Text="!"
                                    ErrorMessage="Invalid user name" 
                                    ValidationExpression="^[a-zA-Z0-9]+$" ValidationGroup="sd"></asp:RegularExpressionValidator>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    Text="*"
                                    ControlToValidate="TextBox_Username"
                                    ErrorMessage="Name required" ValidationGroup="sd">
                                </asp:RequiredFieldValidator>
                            </td>
				</tr>
				<tr>
                            <td>Password</td>
                            <td>
                                <asp:TextBox ID="TextBox_Password" runat="server" TextMode="Password"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_Password"
                                    Text="*"
                                    ErrorMessage="Password required" ValidationGroup="sd"></asp:RequiredFieldValidator>
                            </td>
                        </tr>
                        <tr>
                            <td>Confirm password</td>
                            <td>
                                <asp:TextBox ID="TextBox_ConfirmPassword" runat="server" TextMode="Password"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_ConfirmPassword"
                                    Text="*"
                                    ErrorMessage="Confirm password required" ValidationGroup="sd"></asp:RequiredFieldValidator>
                                <asp:CompareValidator ID="CompareValidator1" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_ConfirmPassword"
                                    ControlToCompare="TextBox_Password"
                                    Text="!"
                                    ErrorMessage="Passwords don't match" ValidationGroup="sd"></asp:CompareValidator>
                            </td>
                        </tr>
						<tr>
                            <td>Type of subscription</td>
                            <td>
                                <asp:DropDownList ID="DropDownList_SubscriptionType" runat="server">
                                    <asp:ListItem Selected="True">-- Select --</asp:ListItem>
                                    <asp:ListItem>Daily</asp:ListItem>
                                    <asp:ListItem>Bi-weekly</asp:ListItem>
									<asp:ListItem>Weekly</asp:ListItem>
									<asp:ListItem>Monthly</asp:ListItem>
                                </asp:DropDownList>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    Text="*"
                                    ControlToValidate="DropDownList_SubscriptionType"
                                    ErrorMessage="Subscription type required" 
                                    InitialValue="-- Select --" ValidationGroup="sd"></asp:RequiredFieldValidator>
                            </td>
                        </tr>
					<tr>
                            <td>
                                <asp:Button ID="Button_SubSubmit" runat="server" Text="Submit" 
									ValidationGroup="sd" onclick="Button_SubSubmit_Click" />
                            </td>
                            <td>
                                <asp:Button ID="Button_SubCancel" CausesValidation=false runat="server" 
									Text="Cancel" onclick="Button_SubCancel_Click" />
                            </td>
                        </tr>
			</table>
		</div>
    </form>
</body>
</html>

<%@ Page Language="C#" AutoEventWireup="true" CodeFile="CandidateRegistration.aspx.cs" Inherits="CandidateRegistration" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Candidate Registration</title>
    <link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <div>
        <div class="main_heading">Candidate Registration</div>
        <div class="logo">
            <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/company_logo.png" />
        </div>
        <ul>
            <li><a href="CompanyHomepage.aspx">Company Homepage</a></li>
        </ul>
        <asp:Label ID="Label_SubmitSuccessMessage" CssClass="success" runat="server"></asp:Label>
        <div class="section">
            <div class="sub_heading">Register yourself here</div>
            <div class="reg_form">
                <form id="form1" defaultbutton="Button_Register" runat="server">
                    <asp:ValidationSummary ID="ValidationSummary_RegistrrationForm" runat="server" 
                        HeaderText="Errors in form" 
                        ShowMessageBox="True" 
                        ShowSummary="False" />
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
                                    ValidationExpression="^[a-zA-Z\s]+([\s]*[a-zA-Z\s]+)+$">
                                </asp:RegularExpressionValidator>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    Text="*"
                                    ControlToValidate="TextBox_Name"
                                    ErrorMessage="Name required">
                                </asp:RequiredFieldValidator>
                            </td>
                        </tr>
                        <tr>
                            <td>Gender</td>
                            <td>
                                <asp:RadioButtonList ID="RadioButtonList_Gender" runat="server" 
                                    RepeatDirection="Horizontal" RepeatLayout="Flow">
                                    <asp:ListItem>Male</asp:ListItem>
                                    <asp:ListItem>Female</asp:ListItem>
                                    <asp:ListItem>Transgender</asp:ListItem>
                                </asp:RadioButtonList>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="RadioButtonList_Gender"
                                    Text="*"
                                    ErrorMessage="Gender required">
                                </asp:RequiredFieldValidator>
                            </td>
                        </tr>
                        <tr>
                            <td>DOB</td>
                            <td>
                                <asp:TextBox ID="TextBox_DOB" runat="server"></asp:TextBox>
                                <%--<asp:RegularExpressionValidator ID="RegularExpressionValidator_DOB" runat="server" 
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    Text="!"                                    
                                    ErrorMessage="Invalid DOB" 
                                    ControlToValidate="TextBox_DOB"
                                    ValidationExpression="^\d{2}/\d{2}/\d{4}$">
                                </asp:RegularExpressionValidator>--%>
                                <asp:CustomValidator ID="CustomValidator1" runat="server" 
                                    SetFocusOnError="True"
                                    ErrorMessage="Invalid DOB" 
                                    ControlToValidate="TextBox_DOB" 
                                    CssClass="invalid" 
                                    Display="Dynamic" 
                                    Text="!"
                                    onservervalidate="CustomValidator1_ServerValidate">
                                </asp:CustomValidator>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_DOB"
                                    Text="*"
                                    ErrorMessage="DOB required">
                                </asp:RequiredFieldValidator>
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
                                    ValidationExpression="^(\w+[+.]*)+@(\w+[+.])+\w+$">
                                </asp:RegularExpressionValidator>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_Email"
                                    Text="*"
                                    ErrorMessage="Email ID required">
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
                                    ErrorMessage="Password required">
                                </asp:RequiredFieldValidator>
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
                                    ErrorMessage="Confirm password required">
                                </asp:RequiredFieldValidator>
                                <asp:CompareValidator ID="CompareValidator1" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_ConfirmPassword"
                                    ControlToCompare="TextBox_Password"
                                    Text="!"
                                    ErrorMessage="Passwords don't match">
                                </asp:CompareValidator>
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
                                    ErrorMessage="Phone number required">
                                </asp:RequiredFieldValidator>
                                <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    ControlToValidate="TextBox_Phone"
                                    Text="!"
                                    ValidationExpression="^\d{10}$"
                                    ErrorMessage="Phone number invalid">
                                </asp:RegularExpressionValidator>
                            </td>
                        </tr>
                        <tr>
                            <td>Address</td>
                            <td>
                                <asp:TextBox ID="TextBox_Address" runat="server"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator8" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    Text="*"
                                    ErrorMessage="Address required"
                                    ControlToValidate="TextBox_Address">
                                </asp:RequiredFieldValidator>
                            </td>
                        </tr>
                        <tr>
                            <td>Nationality</td>
                            <td>
                                <asp:DropDownList ID="DropDownList_Nationality" runat="server">
                                    <asp:ListItem Selected="True">-- Select --</asp:ListItem>
                                    <asp:ListItem>Indian</asp:ListItem>
                                    <asp:ListItem>Other</asp:ListItem>
                                </asp:DropDownList>
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" 
                                    SetFocusOnError="True"
                                    CssClass="invalid"
                                    Display="Dynamic"
                                    Text="*"
                                    ControlToValidate="DropDownList_Nationality"
                                    ErrorMessage="Nationality required" 
                                    InitialValue="-- Select --">
                                </asp:RequiredFieldValidator>
                            </td>
                        </tr>
                        <tr>
                            <td>Profile image</td>
                            <td>
                                <asp:FileUpload ID="FileUpload_ProfilePicture" runat="server" />
                                <asp:Label ID="Label_ProfilePicUploadError" runat="server" CssClass="invalid"></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>Resume</td>
                            <td>
                                <asp:FileUpload ID="FileUpload_Resume" runat="server" />
                                <asp:Label ID="Label_ResumeUploadError" runat="server" CssClass="invalid"></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                <asp:Button ID="Button_Register" runat="server" Text="Register" 
                                    onclick="Button_Register_Click" />
                            </td>
                            <td>
                                <asp:Button ID="Button_Reset" runat="server" Text="Reset" 
                                    onclick="Button_Reset_Click" />
                            </td>
                        </tr>
                    </table>
                </form>
            </div>
        </div>   
    </div>
</body>
</html>

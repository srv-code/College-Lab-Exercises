<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Test 2</title>
    <link type="text/css" rel="stylesheet" href="~/Styles/custom.css" />
    <script type="text/javascript" language="javascript">
        function validate(src, args) {
            // debugger;
            console.log("args=" + args);
            console.log("args.value=" + args.value);
            args.isValid = args.value > 10;
        }
    </script>
</head>
<body>
    <form id="form1" runat="server" defaultbutton="Button1" defaultfocus="TextBox1" >
        <div>
            <div>This is Default2 page</div>

            <asp:ValidationSummary 
                ID="ValidationSummary1" 
                runat="server" 
                HeaderText="Errors in page" 
                ShowMessageBox="True" 
                ShowSummary="False"
                ForeColor="Red" />

            <asp:TextBox 
                ID="TextBox1" 
                runat="server">
            </asp:TextBox>

            <asp:CustomValidator 
                ID="CustomValidator1"
                runat="server" 
                ErrorMessage="Custom error"
                OnServerValidate="CustomValidator1_ServerValidate" 
                ClientValidationFunction="validate"
                ControlToValidate="TextBox1">
            </asp:CustomValidator>
        </div>
        <p>
            <asp:Button ID="Button1" runat="server" Text="Button" onclick="Button1_Click" />
            </p>
    </form>
</body>
</html>

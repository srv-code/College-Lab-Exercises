<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AddingNames.aspx.cs" Inherits="AddingNames" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
    <head runat="server">
        <title>Transfer names</title>
        <link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <div style="float:left; margin-right:50px;">
                    <div>Source:</div>
                    <asp:ListBox ID="ListBox_Source" CssClass="list" runat="server" 
                            SelectionMode="Multiple">
                        <asp:ListItem>A</asp:ListItem>
                        <asp:ListItem>B</asp:ListItem>
                        <asp:ListItem>C</asp:ListItem>
                        <asp:ListItem>D</asp:ListItem>
                        <asp:ListItem>E</asp:ListItem>
                        <asp:ListItem>F</asp:ListItem>
                        <asp:ListItem>G</asp:ListItem>
                        <asp:ListItem>H</asp:ListItem>
                        <asp:ListItem>I</asp:ListItem>
                        <asp:ListItem>J</asp:ListItem>
                    </asp:ListBox>
                </div>

                <div>
                    <div>Destination:</div>
                    <asp:ListBox ID="ListBox_Dest" CssClass="list" runat="server" 
                            SelectionMode="Multiple"></asp:ListBox>
                </div>
                
                <div style="margin-top:20px;">
                    <asp:Button ID="Button_Add" runat="server" Text="Add"
                        onclick="Button_Add_Click"/>
                </div>
            </div>
        </form>
    </body>
</html>

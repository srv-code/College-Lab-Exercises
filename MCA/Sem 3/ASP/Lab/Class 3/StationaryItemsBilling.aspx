<%@ Page Language="C#" AutoEventWireup="true" CodeFile="StationaryItemsBilling.aspx.cs" Inherits="StaionaryBilling" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Stationary Items Billing</title>
    <link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div class="main_heading">Stationary Items Billing</div>
            <div>
                Items: 
                &nbsp;&nbsp;&nbsp;
                <asp:DropDownList ID="DropDownList_Items" runat="server" 
                    onselectedindexchanged="DropDownList_Items_SelectedIndexChanged" 
                    AutoPostBack="True">
                    <asp:ListItem Selected="True" Value="-- Select --">-- Select --</asp:ListItem>
                    <asp:ListItem>Pen</asp:ListItem>
                    <asp:ListItem>Pencil</asp:ListItem>
                    <asp:ListItem>Eraser</asp:ListItem>
                </asp:DropDownList>                
            </div>
            <div>
                <asp:Panel ID="Panel_Image" runat="server" Visible="False">
                    Image:
                    <br/>
                    <asp:Image ID="Image_Item" runat="server" />
                </asp:Panel>                
            </div>
            <div>
                Unit Price:
                &nbsp;&nbsp;&nbsp;
                <asp:Label ID="Label_UnitPrice" runat="server" Text=""></asp:Label>
                &nbsp;&nbsp;&nbsp;
                <asp:Button ID="Button_ShowUnitPrice" runat="server" Text="Show Unit Price" 
                    onclick="Button_ShowUnitPrice_Click" />
            </div>
            <div>
                Enter units required: 
                &nbsp;&nbsp;&nbsp;
                <asp:TextBox ID="TextBox_UnitsRequired" runat="server"></asp:TextBox>
                &nbsp;&nbsp;&nbsp;
                <asp:Button ID="Button_ShowBill" runat="server" Text="Show Bill" 
                    onclick="Button_ShowBill_Click" />
                <asp:Button ID="Button_Reset" runat="server" Text="Reset" 
                    onclick="Button_Reset_Click" />
            </div>
            <div>
                <asp:Panel ID="Panel_Error" runat="server" Visible="False">
                    <asp:Label ID="Label_Error" CssClass="error" runat="server"></asp:Label>
                </asp:Panel>
            </div>
            <div>
                <asp:Panel ID="Panel_Bill" style="margin-top: 20px;" runat="server" Visible="False">
                    Bill information: <br>
                    <asp:TextBox ID="TextBox_Bill" CssClass="output" runat="server" ReadOnly="True" 
                        TextMode="MultiLine"></asp:TextBox>
                </asp:Panel>
            </div>
        </div>
    </form>
</body>
</html>

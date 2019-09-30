using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text;


public partial class StaionaryBilling : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void DropDownList_Items_SelectedIndexChanged(object sender, EventArgs e) {
        Panel_Image.Visible = true;
        switch(DropDownList_Items.SelectedValue) {
            case "Pen":
                Image_Item.ImageUrl = "~/Images/pen.png";
                break;

            case "Pencil":
                Image_Item.ImageUrl = "~/Images/pencil.png";
                break;

            case "Eraser":
                Image_Item.ImageUrl = "~/Images/eraser.png";
                break;

            default:
                Image_Item.ImageUrl = "";
                Panel_Image.Visible=false;
                break;
        }
    }

    int quantityRequired;
    private bool validateInputs() {        
        if (DropDownList_Items.SelectedIndex == 0) {
            Label_Error.Text = "Error: Select an item first!";
            Panel_Error.Visible = true;
            return false;
        }
        if (!int.TryParse(TextBox_UnitsRequired.Text, out quantityRequired)) {
            Label_Error.Text = "Error: Enter a valid quantity!";
            Panel_Error.Visible = true;
            return false;
        }
        if (Label_UnitPrice.Text.Equals("")) {
            Label_Error.Text = "Error: Get unit price!";
            Panel_Error.Visible = true;
            return false;
        }
        Label_Error.Text = "";
        Panel_Error.Visible = false;
        return true;
    }

    private void showBillingInfo() {
        StringBuilder info = new StringBuilder();
        info    .Append("Item: ").Append(DropDownList_Items.SelectedValue).AppendLine()
                .Append("Unit price: ").Append(Label_UnitPrice.Text).AppendLine()
                .Append("Quantity required: ").Append(TextBox_UnitsRequired.Text).AppendLine()
                .Append("Total price: ").Append(double.Parse(Label_UnitPrice.Text) * quantityRequired);
        TextBox_Bill.Text=info.ToString();
        Panel_Bill.Visible = true;
    }

    protected void Button_ShowUnitPrice_Click(object sender, EventArgs e) {
        Panel_Error.Visible = false;
        switch(DropDownList_Items.SelectedValue) {
            case "Pen":
                Label_UnitPrice.Text = "15.0";
                break;

            case "Pencil":
                Label_UnitPrice.Text = "5.0";
                break;

            case "Eraser":
                Label_UnitPrice.Text = "7.0";
                break;

            default:
                Label_UnitPrice.Text = "";
                Label_Error.Text = "Error: Select an item first!";
                Panel_Error.Visible = true;
                break;
        }
    }

    protected void Button_ShowBill_Click(object sender, EventArgs e) {
        if (validateInputs()) {
            System.Diagnostics.Debug.WriteLine("input valid");
            showBillingInfo();
        } else {
            System.Diagnostics.Debug.WriteLine("inputs invalid");
        }
    }

    protected void Button_Reset_Click(object sender, EventArgs e) {
        DropDownList_Items.ClearSelection();        
        Label_UnitPrice.Text = TextBox_UnitsRequired.Text = "";
        Panel_Error.Visible = Panel_Bill.Visible = Panel_Image.Visible = false;
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

	protected void Button_ContSubmit_Click(object sender, EventArgs e) {
		if (Page.IsPostBack) {
			Response.Write("<h1 style=\"color='red';\">Contact details submitted successfully!</h1>");
			clearContactDetailsInputFields();
		}
	}

	private void clearSubscriberDetailsInputFields() {
		// Response.Write("clearSubscriberDetailsInputFields...");
		TextBox_Username.Text 
			= TextBox_Password.Text 
			= TextBox_ConfirmPassword.Text 
				= String.Empty;
		DropDownList_SubscriptionType.ClearSelection();
	}

	private void clearContactDetailsInputFields() {
		// Response.Write("clearContactDetailsInputFields...");
		TextBox_Name.Text
			= TextBox_Phone.Text
			= TextBox_Email.Text
				= String.Empty;
	}

	protected void Button_ContCancel_Click(object sender, EventArgs e) {
		clearContactDetailsInputFields();
		Response.Redirect("~/CancellationDetails.aspx?form=cd");
	}

	protected void Button_SubSubmit_Click(object sender, EventArgs e) {
		if (Page.IsPostBack) {
			Response.Write("<h1 style=\"color='red';\">Subscriber's details submitted successfully!</h1>");
			clearSubscriberDetailsInputFields();
		}
	}

	protected void Button_SubCancel_Click(object sender, EventArgs e) {
		Response.Redirect("~/CancellationDetails.aspx?form=sd");
	}
}
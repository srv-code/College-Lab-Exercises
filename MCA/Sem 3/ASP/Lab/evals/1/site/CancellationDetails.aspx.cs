using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class CancellationDetails : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Label1.Text = "Cancelled " + (Request.QueryString["form"].Equals("cd") ? "contact details" : "subscriber's details") + " fillup!";
    }
}
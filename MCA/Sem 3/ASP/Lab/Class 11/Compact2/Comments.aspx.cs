using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Comments : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Label_WelcomeMessage.Text = "Welcome " + Session["ename"].ToString();
    }
}
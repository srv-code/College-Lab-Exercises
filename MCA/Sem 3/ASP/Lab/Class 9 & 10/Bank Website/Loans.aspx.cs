using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;


public partial class Loans : System.Web.UI.Page {
    protected void Page_Load(object sender, EventArgs e) {
		Debug.Print("-----[Page_Load]-----");
    }

	protected void Menu_PageNavigation_MenuItemClick(object sender, MenuEventArgs e) {
		Response.Redirect("~/" + e.Item.Value + ".aspx");
	}
}
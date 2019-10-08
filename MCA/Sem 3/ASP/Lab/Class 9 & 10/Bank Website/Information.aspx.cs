using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;


public partial class Information : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Debug.Print("----[Page_Load]----");
		if (!IsPostBack)
			MultiView_Information.ActiveViewIndex = 0;
    }

	protected void Menu_Views_MenuItemClick(object sender, MenuEventArgs e) {
		MultiView_Information.ActiveViewIndex = Convert.ToInt32(e.Item.Value);
	}

	protected void Menu_PageNavigation_MenuItemClick(object sender, MenuEventArgs e) {		
		Response.Redirect("~/" + e.Item.Value + ".aspx");
	}
}
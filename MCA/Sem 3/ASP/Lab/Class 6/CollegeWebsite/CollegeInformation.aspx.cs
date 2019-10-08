using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		if(!IsPostBack)
			MultiView_CollegeInfo.ActiveViewIndex = 0;
    }

	protected void Menu_Main_MenuItemClick(object sender, MenuEventArgs e) {
		MultiView_CollegeInfo.ActiveViewIndex = Convert.ToInt32(e.Item.Value);
	}
}
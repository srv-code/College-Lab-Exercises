using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Diagnostics;

public partial class UserImgComment : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Response.Write(Session["ename"].ToString());
    }

	protected void FormView1_DataBound(object sender, EventArgs e) {
		Session["Iname"] = Convert.ToString(DataBinder.Eval(FormView1.DataItem, "ImageName"));

		ControlCollection col = FormView1.Controls;
		Debug.Print("Controls in FormView1:");
		for (int i = 0; i < col.Count; i++) {
			Debug.Print("  [{0}] {1}", i+1, col[i]);
		}

		ListView ll = (ListView)FormView1.FindControl("ListView1");

		ll.Visible = true;
		ll.DataSourceID = "SqlDataSource2";
		ll.DataBind();
	}
	
	protected void TextBox1_TextChanged(object sender, EventArgs e) {
		ListViewItem lt=(ListViewItem)((TextBox)sender).Parent;
		TextBox cmt=(TextBox)lt.FindControl("txtComment");
		SqlDataSource2.InsertParameters["iname"].DefaultValue = Session["Iname"].ToString();
		// SqlDataSource2.InsertParameters["comment"].DefaultValue =((TextBox)sender).Text;
		SqlDataSource2.InsertParameters["comment"].DefaultValue = cmt.Text;
		SqlDataSource2.InsertParameters["ename"].DefaultValue = Session["ename"].ToString();
		SqlDataSource2.Insert();
	}
}
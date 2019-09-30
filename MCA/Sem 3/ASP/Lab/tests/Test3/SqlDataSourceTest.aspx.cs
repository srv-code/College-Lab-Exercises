using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;
using System.Data.SqlClient;

public partial class SqlDataSourceTest : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
    }

	protected void Button_Insert_Click(object sender, EventArgs e) {
		Debug.Print("[Button_Insert_Click]");
		int res = SqlDataSource1.Insert();
		Debug.Print("res={0}", res);
	}

	protected void SqlDataSource1_Inserting(object sender, SqlDataSourceCommandEventArgs e) {
		Debug.Print("[SqlDataSource1_Inserting]");
		foreach (SqlParameter param in e.Command.Parameters) {
			Debug.Print("  param: name={0}, val={1}", param.ParameterName, param.Value);
			if (param.Value == null) {
				Debug.Print("Cancelling...");
				e.Cancel = true;
				return;
			}
		}
	}
	protected void SqlDataSource1_Inserted(object sender, SqlDataSourceStatusEventArgs e) {
		Debug.Print("[SqlDataSource1_Inserted]");
		foreach (SqlParameter param in e.Command.Parameters) {
			Debug.Print("  param: name={0}, val={1}", param.ParameterName, param.Value);
			if (param.Value == null) {
				Debug.Print("Cancelling...");
				// e.Cancel = true;
				return;
			}
		}
	}
}
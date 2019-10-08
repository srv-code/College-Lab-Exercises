using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;

public partial class Identify : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
    }

	protected void Button1_Click(object sender, EventArgs e) {
		SqlDataReader sr;
		SqlConnection MyConnection = new SqlConnection();
		MyConnection.ConnectionString = ConfigurationManager.ConnectionStrings["ConnectionString2"].ConnectionString;
		SqlCommand MyCommand = new SqlCommand();
		MyCommand.CommandText = "SELECT * FROM emppp";
		MyCommand.CommandType = CommandType.Text;
		MyCommand.Connection = MyConnection;
		MyCommand.Connection.Open();
		sr = MyCommand.ExecuteReader(CommandBehavior.CloseConnection);
		while (sr.Read()) {
			if ((sr["ename"].ToString()) == TextBox1.Text && (sr["password"].ToString()) == TextBox2.Text) {
				Session["ename"] = TextBox1.Text; Response.Redirect("~/userimgcomment.aspx");
			} else {
				Response.Write("Authentication Failed");
			}
		}
	}
}
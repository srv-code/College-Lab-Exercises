using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;

public partial class Login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
    }

	protected void Button_Login_Click(object sender, EventArgs e) {
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
			if ((sr["ename"].ToString()) == TextBox_Username.Text && (sr["password"].ToString()) == TextBox_Password.Text) {
				Session["ename"] = TextBox_Username.Text; 
				Response.Redirect("~/Comments.aspx");
			} else {
				Label_Error.Text = "Authentication Failed";
			}
		}
	}
}
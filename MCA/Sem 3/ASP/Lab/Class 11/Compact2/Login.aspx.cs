using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Configuration;
using System.Data.SqlClient;


public partial class Login : System.Web.UI.Page
{
	static readonly string databaseName = "CommentsDb";
	static readonly string connectionString = 
		WebConfigurationManager.ConnectionStrings[databaseName].ConnectionString;


    protected void Page_Load(object sender, EventArgs e) {
		if (!IsPostBack) {
			Label_Error.Text = String.Empty;
		}
    }

	protected void Button_Login_Click(object sender, EventArgs e) {
		SqlConnection con = new SqlConnection(connectionString);
		const string sql = "SELECT password FROM Employees WHERE name=@name";
		SqlCommand cmd = new SqlCommand(sql, con);
		cmd.Parameters.AddWithValue("@name", TextBox_Username.Text);
		List<string> pwds = new List<string>();
		using (con) {
			con.Open();
			SqlDataReader reader = cmd.ExecuteReader();
			while (reader.Read()) {
				pwds.Add(reader[0].ToString());
			}
			reader.Close();
		}

		if (pwds.Contains(TextBox_Password.Text))
		{
			Session["ename"] = TextBox_Username.Text;
			Response.Redirect("~/Comments.aspx");
		} else
			Label_Error.Text = "Authentication failed!";
	}
}
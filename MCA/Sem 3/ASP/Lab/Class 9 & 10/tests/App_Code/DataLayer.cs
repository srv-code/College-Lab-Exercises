using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;
using System.Diagnostics;

public class DataLayer {
	private readonly string conString;

	public DataLayer() {
		conString = WebConfigurationManager.ConnectionStrings["dbBank"].ConnectionString;
	}

	public SqlDataReader GetEmpDetails(int startRowIndex, int maximumRows) {
		HttpContext cont = HttpContext.Current;
		Debug.Print("GetEmpdetails() invoked: startRowIndex={0}, maximumRows={1}", startRowIndex, maximumRows);

		SqlConnection con = new SqlConnection(conString);

		SqlCommand cmd = new SqlCommand();
		cmd.Connection = con;
		cmd.CommandText = "GetPagedEmpRecords";
		cmd.CommandType = CommandType.StoredProcedure;
		// cmd.CommandText = "SELECT UserID,UserName,City,Designation FROM Employee_Details";
		cmd.Parameters.AddWithValue("@startRowIdx", startRowIndex);
		cmd.Parameters.AddWithValue("@maxRows", maximumRows);

		con.Open();
		return cmd.ExecuteReader(CommandBehavior.CloseConnection);
	}

	public int GetEmpCount() {
		HttpContext context = HttpContext.Current;
		if (context.Cache["empcount"] == null)
			context.Cache["empcount"] = GetEmpCountFromDB();
		Debug.Print("GetempCount() invoked: No. of Records={0}", context.Cache["empcount"]);
		return (int)context.Cache["empcount"];
	}

	private int GetEmpCountFromDB() {
		int result = 0;

		// Initialize connection
		SqlConnection con = new SqlConnection(conString);

		// Initialize command
		SqlCommand cmd = new SqlCommand();
		cmd.Connection = con;
		cmd.CommandText = "SELECT Count(*) FROM employees"; // "SELECT Count(*) FROM Employee_Details";

		// Execute command
		using (con) {
			con.Open();
			result = (int)cmd.ExecuteScalar();
		}
		return result;
	 }

	public void UpdateEmp(int id, string name, string address) {
		// Create Command
		SqlConnection con = new SqlConnection(conString);

		SqlCommand cmd = new SqlCommand();
		cmd.Connection = con;
		cmd.CommandText = "update employees set name=@name, address=@address where id=@id";

		// Add parameters
		cmd.Parameters.AddWithValue("@id", id);
		cmd.Parameters.AddWithValue("@name", name);
		cmd.Parameters.AddWithValue("@address", address);

		// Execute command
		using (con) {
			con.Open();
			cmd.ExecuteNonQuery();
		}
	 }
}
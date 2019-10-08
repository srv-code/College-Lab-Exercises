using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Diagnostics;


public class EmpData {
	private static readonly string connectionString;

	static EmpData() {
		Debug.Print("constructor EmpData() invoked");
		connectionString = WebConfigurationManager.ConnectionStrings["dbBank"].ConnectionString;
	}

	public SqlDataReader GetAllRecords() {
		Debug.Print("GetAllRecords() invoked");
		SqlConnection con = new SqlConnection(connectionString);
		const string sql = "select id, name, address from employees";
		SqlCommand cmd = new SqlCommand(sql, con);
		con.Open();
		return cmd.ExecuteReader(CommandBehavior.CloseConnection);
	}

	public SqlDataReader GetPagedRecords(int startRowIndex, int maximumRows) {
		Debug.Print("GetPagedRecords(startRowIndex={0}, maximumRows={1}) invoked", startRowIndex, maximumRows);

		SqlConnection con = new SqlConnection(connectionString);

		const string procedureName = "GetPagedEmpRecords";
		SqlCommand cmd = new SqlCommand(procedureName, con);
		cmd.CommandType = CommandType.StoredProcedure;

		cmd.Parameters.AddWithValue("@startRowIdx", startRowIndex);
		cmd.Parameters.AddWithValue("@maxRows", maximumRows);

		con.Open();
		return cmd.ExecuteReader(CommandBehavior.CloseConnection);
	}

	public void Insert(string name, string address) {
		Debug.Print("invoked: Insert(name={0}, address={1})", name, address);

		SqlConnection con = new SqlConnection(connectionString);
		const string sql = "INSERT INTO employees (name, address) VALUES (@name, @address)";
		SqlCommand cmd = new SqlCommand(sql, con);
		cmd.Parameters.AddWithValue("@name", name);
		cmd.Parameters.AddWithValue("@address", address);
		using (con) { 
			con.Open();
			int rows = cmd.ExecuteNonQuery();
			Debug.Print("insert: rows affected={0}", rows);
		}
	}

	public void Update(int id, string name, string address) {
		Debug.Print("invoked: Update(id={0}, name={1}, address={2})", id, name, address);

		SqlConnection con = new SqlConnection(connectionString);
		const string sql = "UPDATE employees SET name=@name, address=@address WHERE id=@id";
		SqlCommand cmd = new SqlCommand(sql, con);
		cmd.Parameters.AddWithValue("@id", id);
		cmd.Parameters.AddWithValue("@name", name);
		cmd.Parameters.AddWithValue("@address", address);
		using (con) {
			con.Open();
			int rows = cmd.ExecuteNonQuery();
			Debug.Print("update: rows affected={0}", rows);
		}
	}

	public void Delete(int id) {
		Debug.Print("invoked: Delete(id={0})", id);

		SqlConnection con = new SqlConnection(connectionString);
		const string sql= "DELETE FROM employees WHERE id=@id";
		SqlCommand cmd = new SqlCommand(sql, con);
		cmd.Parameters.AddWithValue("@id", id);
		using (con) {
			con.Open();
			int rows = cmd.ExecuteNonQuery();
			Debug.Print("delete: rows affected={0}", rows);
		}
	}

	public SqlDataReader GetPagedSortedRecords(string sortExpression, int startRowIndex, int maximumRows) {
		Debug.Print("invoked: GetPagedSortedRecords: sortExpression={0}, startRowIndex={1}, maximumRows={2}", 
			sortExpression, startRowIndex, maximumRows);

		SqlConnection con = new SqlConnection(connectionString);
		const string procedureName = "GetPagedSortedEmpRecords";
		SqlCommand cmd = new SqlCommand(procedureName, con);
		cmd.CommandType = CommandType.StoredProcedure;
		cmd.Parameters.AddWithValue("@sortExpr", sortExpression);
		cmd.Parameters.AddWithValue("@startRowIdx", startRowIndex);
		cmd.Parameters.AddWithValue("@maxRows", maximumRows);
		con.Open();
		return cmd.ExecuteReader(CommandBehavior.CloseConnection);
	}

	public int GetRecordCount() {
		Debug.Print("GetRecordCount() invoked");

		const string cacheVariable = "emp_count";
		HttpContext context = HttpContext.Current;
		Debug.Print("  cacheVariable={0}", context.Cache[cacheVariable]);

		if (context.Cache[cacheVariable] == null)
			context.Cache[cacheVariable] = GetRecordCountFromDb();

		Debug.Print("  fetched data={0}", context.Cache[cacheVariable]);
		return (int)context.Cache[cacheVariable];
	}

	private int GetRecordCountFromDb() {
		Debug.Print("GetRecordCountFromDb() invoked");

		SqlConnection con = new SqlConnection(connectionString);
		const string sql = "select count(*) from employees";
		SqlCommand cmd = new SqlCommand(sql, con);

		int count = 0;
		using (con) { 
			con.Open();
			count = (int)cmd.ExecuteScalar();
		}

		Debug.Print("  count={0}", count);
		return count;
	}
}
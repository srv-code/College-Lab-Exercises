using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Diagnostics;
using System.Data.SqlClient;
using System.Data;


namespace DbOperations {
	public class BranchData {
		private readonly string cacheVariableName = "branch_count";

		public void Insert(string name, string city, int assets) {
			Debug.Print("Insert: <init>(name={0}, city={1}, assets={2})", 
				name, city, assets);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "INSERT INTO branches (name, city, assets) VALUES (@name, @city, @assets)";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@name", name);
			cmd.Parameters.AddWithValue("@city", city);
			cmd.Parameters.AddWithValue("@assets", assets);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Insert: rows affected={0}", rows);
			}
			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
		}

		public void Update(string name, string city, int assets) {
			Debug.Print("Update: <invoked>(name={0}, city={1}, assets={2})", 
				name, city, assets);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "UPDATE branches SET assets=@assets WHERE name=@name AND city=@city";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@name", name);
			cmd.Parameters.AddWithValue("@city", city);
			cmd.Parameters.AddWithValue("@assets", assets);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Update: rows affected={0}", rows);
			}
		}

		public void Delete(string name, string city) {
			Debug.Print("Delete: <invoked>(name={0}, city={1})", name, city);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "DELETE FROM branches WHERE name=@name";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@name", name);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Delete: rows affected={0}", rows);
			}
			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
		}

		public SqlDataReader GetPagedSortedRecords(string sortExpression, int startRowIndex, int maximumRows) {
			Debug.Print("GetPagedSortedRecords: <invoked>(sortExpression={0}, startRowIndex={1}, maximumRows={2})",
				sortExpression, startRowIndex, maximumRows);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string procedureName = "GetPagedSortedBranchesRecords";
			SqlCommand cmd = new SqlCommand(procedureName, con);
			cmd.CommandType = CommandType.StoredProcedure;
			cmd.Parameters.AddWithValue("@sortExpr", sortExpression);
			cmd.Parameters.AddWithValue("@startRowIdx", startRowIndex);
			cmd.Parameters.AddWithValue("@maxRows", maximumRows);
			con.Open();
			return cmd.ExecuteReader(CommandBehavior.CloseConnection);
		}

		public int GetRecordCount() {
			Debug.Print("GetRecordCount: <invoked>");

			HttpContext context = HttpContext.Current;
			Debug.Print("GetRecordCount: cache[{0}]={1}", 
				cacheVariableName, context.Cache[cacheVariableName]);

			if (context.Cache[cacheVariableName] == null)
				context.Cache[cacheVariableName] = FetchDataRowCountFromDb();

			Debug.Print("GetRecordCount: {0}={1}", 
				cacheVariableName, context.Cache[cacheVariableName]);
			return Convert.ToInt32(context.Cache[cacheVariableName]);
		}

		private int FetchDataRowCountFromDb() {
			Debug.Print("FetchDataRowCountFromDb: <invoked>");

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "SELECT COUNT(*) FROM branches";
			SqlCommand cmd = new SqlCommand(sql, con);
			int count = 0;
			using (con) {
				con.Open();
				count = Convert.ToInt32(cmd.ExecuteScalar());
			}
			Debug.Print("FetchDataRowCountFromDb: count={0}", count);
			return count;
		}
	}
}
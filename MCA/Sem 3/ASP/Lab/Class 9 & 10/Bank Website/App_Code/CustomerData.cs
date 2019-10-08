using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Diagnostics;


namespace DbOperations {
	public class CustomerData {
		private readonly string cacheVariableName = "cust_count";

		public void Insert(string name, string street, string city) {
			Debug.Print("Insert: <init>(name={0}, street={1}, city={2})",
				name, street, city);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "INSERT INTO customers (name, street, city) VALUES (@name, @street, @city)";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@name", name);
			cmd.Parameters.AddWithValue("@street", street);
			cmd.Parameters.AddWithValue("@city", city);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Insert: rows affected={0}", rows);
			}
			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
		}

		public void Update(int id, string name, string street, string city) {
			Debug.Print("Update: <invoked>(id={0}, name={1}, street={2}, city={3})", 
				id, name, street, city);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "UPDATE customers SET name=@name, street=@street, @city=city WHERE id=@id";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@id", id);
			cmd.Parameters.AddWithValue("@name", name);
			cmd.Parameters.AddWithValue("@street", street);
			cmd.Parameters.AddWithValue("@city", city);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Update: rows affected={0}", rows);
			}
		}

		public void Delete(int id) {
			Debug.Print("Delete: <invoked>(id={0})", id);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "DELETE FROM customers WHERE id=@id";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@id", id);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Delete: rows affected={0}", rows);
			}
			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
		}

		public SqlDataReader GetPagedDataRows(int startRowIndex, int maximumRows) {
			Debug.Print("GetCustomers: <invoked>(startRowIndex={0}, maximumRows={1})", 
				startRowIndex, maximumRows);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string procedureName = "GetPagedCustomerRecords";
			SqlCommand cmd = new SqlCommand(procedureName, con);
			cmd.CommandType = CommandType.StoredProcedure;
			cmd.Parameters.AddWithValue("@startRowIdx", startRowIndex);
			cmd.Parameters.AddWithValue("@maxRows", maximumRows);

			con.Open();
			return cmd.ExecuteReader(CommandBehavior.CloseConnection);
		}

		public SqlDataReader GetPagedSortedDataRows(string sortExpression, int startRowIndex, int maximumRows) {
			Debug.Print("GetPagedSortedDataRows: <invoked>(sortExpression={0}, startRowIndex={1}, maximumRows={2})",
				sortExpression, startRowIndex, maximumRows);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string procedureName = "GetPagedSortedCustomerRecords";
			SqlCommand cmd = new SqlCommand(procedureName, con);
			cmd.CommandType = CommandType.StoredProcedure;
			cmd.Parameters.AddWithValue("@sortExpr", sortExpression);
			cmd.Parameters.AddWithValue("@startRowIdx", startRowIndex);
			cmd.Parameters.AddWithValue("@maxRows", maximumRows);

			con.Open();
			return cmd.ExecuteReader(CommandBehavior.CloseConnection);
		}

		public int GetDataRowCount() {
			Debug.Print("GetDataRowCount: <invoked>");

			HttpContext context = HttpContext.Current;
			Debug.Print("GetDataRowCount: cache[{0}]={1}",
				cacheVariableName, context.Cache[cacheVariableName]);
			if (context.Cache[cacheVariableName] == null)
				context.Cache[cacheVariableName] = FetchDataRowCountFromDb();
			Debug.Print("GetDataRowCount: {0}={1}", 
				cacheVariableName, context.Cache[cacheVariableName]);
			return Convert.ToInt32(context.Cache[cacheVariableName]);
		}

		private int FetchDataRowCountFromDb() {
			Debug.Print("FetchDataRowCountFromDb: <invoked>");

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "SELECT COUNT(*) FROM customers";
			SqlCommand cmd = new SqlCommand(sql, con);
			int count;
			using (con) {
				con.Open();
				count = Convert.ToInt32(cmd.ExecuteScalar());
			}
			Debug.Print("FetchDataRowCountFromDb: count={0}", count);
			return count;
		}
	}
}
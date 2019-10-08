using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Diagnostics;

namespace DbOperations {
	public class BorrowerData {
		private readonly string cacheVariableName = "borrower_count";

		private bool RecordAlreadyExists(SqlConnection con, int customer_id, string branch_name, int loan_number) {
			Debug.Print("RecordAlreadyExists: <invoked>(con={0}, customer_id={1}, branch_name={2}, loan_number={3}", 
				con, customer_id, branch_name, loan_number);

			const string sql = "SELECT COUNT(*) FROM borrowers WHERE " +
				"customer_id=@customer_id AND branch_name=@branch_name AND loan_number=@loan_number";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@customer_id", customer_id);
			cmd.Parameters.AddWithValue("@branch_name", branch_name);
			cmd.Parameters.AddWithValue("@loan_number", loan_number);
			return Convert.ToInt32(cmd.ExecuteScalar()) > 0;
		}

		public void Insert(int customer_id, string branch_name, int loan_number) {
			Debug.Print("Insert: <init>(customer_id={0}, branch_name={1}, loan_number={2})",
				customer_id, branch_name, loan_number);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			con.Open();

			/* check if the tuple is already present */
			if(RecordAlreadyExists(con, customer_id, branch_name, loan_number)) {
				con.Close();
				return;
			}

			const string sql = "INSERT INTO borrowers (customer_id, branch_name, loan_number) " +
				"VALUES (@customer_id, @branch_name, @loan_number)";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@customer_id", customer_id);
			cmd.Parameters.AddWithValue("@branch_name", branch_name);
			cmd.Parameters.AddWithValue("@loan_number", loan_number);
			
			int rows = cmd.ExecuteNonQuery();
			Debug.Print("Insert: rows affected={0}", rows);
			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
			con.Close();
		}

		public void Delete(int customer_id, string branch_name, int loan_number) {
			Debug.Print("Delete: <init>(customer_id={0}, branch_name={1}, loan_number={2})",
				customer_id, branch_name, loan_number);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			con.Open();

			if (RecordAlreadyExists(con, customer_id, branch_name, loan_number)) {
				const string sql = "DELETE FROM borrowers WHERE " +
					"customer_id=@customer_id AND branch_name=@branch_name AND loan_number=@loan_number";
				SqlCommand cmd = new SqlCommand(sql, con);
				cmd.Parameters.AddWithValue("@customer_id", customer_id);
				cmd.Parameters.AddWithValue("@branch_name", branch_name);
				cmd.Parameters.AddWithValue("@loan_number", loan_number);				
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Delete: rows affected={0}", rows);

				/* force updating tuple count */
				HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
				return;
			}
			con.Close();
		}

		public SqlDataReader GetRecords() {
			Debug.Print("GetRecords: <invoked>");

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "SELECT customer_id, branch_name, loan_number FROM borrowers ORDER BY 1";
			SqlCommand cmd = new SqlCommand(sql, con);
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
			const string sql = "SELECT COUNT(*) FROM borrowers";
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
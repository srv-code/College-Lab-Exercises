using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Diagnostics;

namespace DbOperations {
	public class PaymentData {
		private readonly string cacheVariableName = "payment_count";

		public void Insert(int amount, string branch_name, int customer_id) {
			Debug.Print("Insert: <init>(amount={0}, branch_name={1}, customer_id={2})",
				amount, branch_name, customer_id);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string sql = "INSERT INTO loans (amount, branch_name, customer_id) VALUES (@amount, @branch_name, @customer_id)";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@amount", amount);
			cmd.Parameters.AddWithValue("@branch_name", branch_name);
			cmd.Parameters.AddWithValue("@customer_id", customer_id);
			using (con) {
				con.Open();
				int rows = cmd.ExecuteNonQuery();
				Debug.Print("Insert: rows affected={0}", rows);
			}
			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();
		}

		public SqlDataReader GetPagedSortedRecords(string sortExpression, int startRowIndex, int maximumRows) {
			Debug.Print("GetPagedSortedRecords: <invoked>(sortExpression={0}, startRowIndex={1}, maximumRows={2})",
				sortExpression, startRowIndex, maximumRows);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			const string procedureName = "GetPagedSortedLoanRecords";
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
			const string sql = "SELECT COUNT(*) FROM loans";
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
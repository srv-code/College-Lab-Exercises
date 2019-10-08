using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Data.SqlClient;
using System.Data;
using System.Diagnostics;

namespace DbOperations {
	public class LoanData {
		private readonly string cacheVariableName = "loan_count";

		private int GetBranchAssets(SqlConnection con, string branch_name) {
			Debug.Print("GetBranchAssets: <invoked>(con={0}, branch_name={1})", con, branch_name);

			const string sql = "SELECT assets FROM branches WHERE name=@name";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@name", branch_name);
			return Convert.ToInt32(cmd.ExecuteScalar());
		}

		private void UpdateBranchAssets(SqlConnection con, string branch_name, int newAmount) {
			Debug.Print("UpdateBranchAssets: con={0}, branch_name={1}, newAmount={2}",
				con, branch_name, newAmount);

			const string sql = "UPDATE branches SET assets=@assets WHERE name=@name";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@assets", newAmount);
			cmd.Parameters.AddWithValue("@name", branch_name);
			int rows = Convert.ToInt32(cmd.ExecuteScalar());
			Debug.Print("UpdateBranchAssets: updating branches.assets: rows affected={0}", rows);
		}

		private int GetLoanNumber(SqlConnection con, int amount, string branch_name, int customer_id) {
			Debug.Print("GetLoanNumber: <invoked>(con={0}, amount={1}, branch_name={2}, int customer_id={3})",
				con, amount, branch_name, customer_id);

			const string sql = "SELECT TOP 1 number FROM loans WHERE amount=@amount AND branch_name=@branch_name AND customer_id=@customer_id";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@amount", amount);
			cmd.Parameters.AddWithValue("@branch_name", branch_name);
			cmd.Parameters.AddWithValue("@customer_id", customer_id);
			return Convert.ToInt32(cmd.ExecuteNonQuery());
		}

		public void Insert(int amount, string branch_name, int customer_id) {
			Debug.Print("Insert: <init>(amount={0}, branch_name={1}, customer_id={2})",
				amount, branch_name, customer_id);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			con.Open();

			/* check if the requested amount is available in the bank branch */
			int maxAssets = GetBranchAssets(con, branch_name);
			if (maxAssets < amount) {
				con.Close();
				throw new ArgumentException("Cannot sanction requested amount. Maximum loan amount: " + maxAssets);
			}

			/* update the new assets amount in branches table */
			UpdateBranchAssets(con, branch_name, maxAssets-amount);

			/* insert a record in loans table */
			const string sql = "INSERT INTO loans (amount, branch_name, customer_id, cleared) VALUES (@amount, @branch_name, @customer_id, @cleared)";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@amount", amount);
			cmd.Parameters.AddWithValue("@branch_name", branch_name);
			cmd.Parameters.AddWithValue("@customer_id", customer_id);
			cmd.Parameters.AddWithValue("@cleared", 0);

			int rows = cmd.ExecuteNonQuery();
			Debug.Print("Insert: rows affected={0}", rows);

			/* add a new entry in borrowers table */
			new BorrowerData().Insert(customer_id, branch_name, GetLoanNumber(con, amount, branch_name, customer_id));

			/* force updating tuple count */
			HttpContext.Current.Cache[cacheVariableName] = FetchDataRowCountFromDb();

			con.Close();
		}

		public void Delete(int number, int amount, string branch_name, int customer_id) {
			Debug.Print("Delete: <invoked>(number={0}, amount={1}, branch_name={2})", 
				number, amount, branch_name);

			SqlConnection con = new SqlConnection(DbStrings.dbConnectionString);
			con.Open();

			/* update matching row, set cleared=true */
			string sql = "UPDATE loans SET cleared=@cleared WHERE number=@number";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@number", number);
			cmd.Parameters.AddWithValue("@cleared", 1);

			/* update the new assets amount in branches table */
			UpdateBranchAssets(con, branch_name, GetBranchAssets(con, branch_name) + amount);
			
			int rows = Convert.ToInt32(cmd.ExecuteScalar());
			Debug.Print("Delete: updating loans.cleared: rows affected={0}", rows);

			/* insert a new record in payments table */
			new PaymentData().Insert(amount, branch_name, customer_id);

			/* remove from borrowers table  */
			new BorrowerData().Delete(customer_id, branch_name, number);

			con.Close();
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
			const string sql = "SELECT COUNT(*) FROM loans WHERE cleared=@cleared";
			SqlCommand cmd = new SqlCommand(sql, con);
			cmd.Parameters.AddWithValue("@cleared", 0);
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
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Diagnostics;
using System.Web.Configuration;


namespace DbOperations {
	class DbStrings {
		public static readonly string dbConnectionString;
		public static readonly string dbName;
	
		static DbStrings() {
			Debug.Print("DbStrings: <init>");
			dbName = "BankDb";
			dbConnectionString = WebConfigurationManager.ConnectionStrings[dbName].ConnectionString;
			Debug.Print("DbStrings: connectionString={0}, databaseName={1}", 
				dbConnectionString, dbName);
		}
	}
}
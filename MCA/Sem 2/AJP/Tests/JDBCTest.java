import java.sql.*;


/**
 * Java Data Base Connectivity
 * 	Testing for database connectivity and displaying 
 * 		the result set from a database table.
*/
/* Accesses MS Access DB: filename=StudentDB.accdb; DB name=StudentDB */
public class JDBCTest {
	public static void main(String[] args) {
		String driver = "sun.jdbc.odbc.JdbcOdbcDriver";
		// change this to whatever your DSN is
		String dataSourceName = "StudentDB";
		String dbURL = "jdbc:odbc:" + dataSourceName;
		String username = "";
		String password = "";
		
		try {
			Class.forName(driver);
			Connection con = DriverManager.getConnection(dbURL, username, password);
			Statement st = con.createStatement();
			String query = "select RegNo, Name from Student order by RegNo";
			ResultSet rs = st.executeQuery(query);

			while(rs.next()) {
				System.out.printf("%4d \t %-10s \n", rs.getInt("RegNo"), rs.getString("Name"));			
			}
		} catch(Exception e) {
			System.err.println("Error: " + e);
			e.printStackTrace(System.err);
		}
	}
}
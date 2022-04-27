import java.sql.*;

public class MysqlConnect{
public static void main(String[] args) {
	System.out.println("MySQL Connect Example");
	Connection conn = null;
	String url = "jdbc:mysql://localhost:3306/";
	String dbName = "librarydb";
	String driver = "com.mysql.jdbc.Driver";
	String userName = "root"; 
	String password = "";

	try{
		Class.forName(driver).newInstance();
		conn = DriverManager.getConnection(url+dbName,userName,password);
		System.out.println("Connected to database");
	}catch(Exception e) {
		e.printStackTrace();
	
	} 

	try{
		Statement st = conn.createStatement();
		int val = st.executeUpdate("INSERT INTO publisher VALUES('P888','Giorgos Pappas')");
		System.out.println("1 row affected");
	}catch(SQLException s){
		System.out.println("SQL statement is not executed!");
	}

    try{
		Statement st = conn.createStatement();
		ResultSet res = st.executeQuery("SELECT * FROM publisher");
		System.out.println("PUBLISHER_CODE: " + "\t" + "PUBLISHER_NAME: ");
		while (res.next()) {
			String i = res.getString("PUBLISHER_CODE");
			String s = res.getString("PUBLISHER_NAME");
			System.out.println(i + "\t\t" + s);
		}
		}catch(SQLException s){
			System.out.println("SQL code does not execute.");
		} 

		conn.close();
//		System.out.println("Disconnected from database");
}
}

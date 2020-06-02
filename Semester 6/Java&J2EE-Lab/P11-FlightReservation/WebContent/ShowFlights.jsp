<%@ page import="java.sql.*"%>
<%@ page import="java.io.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Show Flights</title>
</head>
<body>
	<%
	String day = request.getParameter("day");
	try{
		Class.forName("com.mysql.jdbc.Driver");
		Connection conn = (Connection)DriverManager.getConnection("jdbc:mysql://localhost:3306/flightdb","root","abcd");
		Statement stmt = (Statement)conn.createStatement();
		ResultSet rs;
		rs= stmt.executeQuery("select * from flight where weekdays LIKE '%"+day+"%';");
		out.println("Flight No. - Flight Name - Weekdays<br>");
		while(rs.next()){
			out.println(rs.getInt(1)+" - "+rs.getString(2)+" - "+rs.getString(3)+"<br>");
			out.println();
		}
	}catch(Exception e){
		e.printStackTrace();
	}
	%>
</body>
</html>
<%@ page import="java.util.*"%>
<%@ page import="java.sql.*"%>
<%@ page import="java.io.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>View Displays</title>
</head>
	<body>
		<%
			String name = request.getParameter("name");
			String number = request.getParameter("number");
			int fno = Integer.parseInt(request.getParameter("fno"));
			int sno = new Random().nextInt(500)+1;
			String date = request.getParameter("date");
			String url = "jdbc:mysql://localhost:3306/flightdb";
	
			try{
				Class.forName("com.mysql.jdbc.Driver");
				Connection conn = (Connection)DriverManager.getConnection(url,"root","abcd");
				if(conn!=null){
					Statement stmt = (Statement)conn.createStatement();
					try{
						stmt.executeUpdate("insert into seatreservation values('"+fno+"','"+date+"','"+sno+"','"+name+"','"+number+"');");
						out.println("<br>Name: "+name+"<br>Phone No.: "+number+"<br>Date: "+date+"<br>Flight No.: "+fno+"<br>Seat No.: "+sno);
					}
					catch(Exception e){
						out.println("Could not make a reservation");
					}
				}
			}catch(Exception e){
				e.printStackTrace();
			}
		%>
	</body>
</html>
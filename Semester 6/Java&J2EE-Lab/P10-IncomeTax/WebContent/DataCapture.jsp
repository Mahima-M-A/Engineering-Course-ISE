<%@ page import="java.util.*"%>
<%@ page import="java.io.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Data Capture</title>
</head>
<body>
	<%
		HashMap<String, String> hm = new HashMap<String, String>();
		hm.put("admin", "admin");
		String name = request.getParameter("name");
		String pass = request.getParameter("pass");
		if (hm.containsKey(name) && pass.equals(hm.get(name))) {
			out.println("Welcome " + name + "<br>");
			out.println(new Date());
	%>
	<form action="CalculateTax.jsp" method="get">
		Name : <input type="text" name="name"><br>
		Profession <select name="profession">
			<option>Engineer</option>
			<option>Doctor</option>
			<option>Architect</option>
		</select><br> 
		Gender <select name="gender">
			<option>Male</option>
			<option>Female</option>
		</select> <br>
		AnnualIncome: <input type="text" name="salary"><br>
		<input type="submit" value="Calculate Tax">

	</form>
	<%
		} else {
	%>
	<jsp:forward page="Login.html"></jsp:forward>
	<%
		}
	%>
</body>
</html>
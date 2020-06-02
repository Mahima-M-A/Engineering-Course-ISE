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
		hm.put("name1", "pass1");
		hm.put("name2", "pass2");
		String name = request.getParameter("name");
		String pass = request.getParameter("pass");
		PrintWriter pout = response.getWriter();
		if (hm.containsKey(name) && pass.equals(hm.get(name))) {
			pout.println("Welcome " + name + "\n");
			pout.println(new Date());
	%>
	<form action="CalculateTax.jsp" method="get">
		Name : <input type="text" name="name">
		Profession <select name="prof">
			<option>Engineer</option>
			<option>Doctor</option>
		</select><br> Gender <select name="gender">
			<option>Male</option>
			<option>Female</option>
		</select>
		AnnualIncome: <input type="text" name="salary">
		CalculateTax<input type="submit">

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
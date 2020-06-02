<%@page import="java.io.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Calculate Tax</title>
</head>
<body>
<%
	int income = Integer.parseInt(request.getParameter("salary"));
	double tax = 0;
	if(income <= 100000){
	}
	if(income>100000 && income<=500000){
		tax = (income-100000)*0.15;
	}
	if(income > 500000){
		tax = (income-500000)*0.20 + 400000*0.15;
	}
	out.print("Tax amount:" + tax);
%>
</body>
</html>
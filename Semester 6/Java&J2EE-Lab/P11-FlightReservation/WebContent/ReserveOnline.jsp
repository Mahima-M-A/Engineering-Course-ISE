<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Reserve Online</title>
</head>
<body>
	<form action="ViewDisplays.jsp" method="post">
		Name: <input type="text" name="name">
		Number: <input type="text" name="number">
		Flight Number: <input type="text" name="fno">
		Date: <input type="text" name="date">
		<input type="submit" value="Reserve Seat">
	</form>
	<form action="ShowFlights.jsp" method="get">
		Day: <input type="text" name="day">
		<input type="submit" value="Show Flights">
	</form>
</body>
</html>
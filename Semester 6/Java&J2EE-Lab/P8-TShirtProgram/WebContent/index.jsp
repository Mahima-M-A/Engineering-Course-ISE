<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>TShirts</title>
</head>
<body>
	<form action="PlaceOrder" method="post">
		T-Shirt Accessories: <input type="checkbox" name="accessory" value="Belt"/>Belt
		<input type="checkbox" name="accessory" value="Cap"/>Cap
		<input type="checkbox" name="accessory" value="Hair-Band"/>Hair-Band<br>
		Tag-Line: <input type="text" name="tagline" size="50"/><br>
		T-Shirt Feature: <input type="radio" name="pocket" value="ChestPocket"/>Chest Pocket
		<input type="radio" name="pocket" value="NoChestPocket"/>No Chest Pocket<br>
		T-Shirt Color: <select name="color">
		<option>Red</option>
		<option>Blue</option>
		<option>Green</option>
		</select><br>
		<input type="submit" value="Click Me"/>	
	</form>
</body>
</html>
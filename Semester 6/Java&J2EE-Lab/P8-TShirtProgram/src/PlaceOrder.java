import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class PlaceOrder
 */
@WebServlet("/PlaceOrder")
public class PlaceOrder extends HttpServlet {
	private static final long serialVersionUID = 1L;
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		String[] Accessories={};
		Accessories=request.getParameterValues("accessory");
		String accessories="";
		String tagLine=request.getParameter("tagline");
		String pocket=request.getParameter("pocket");
		String color=request.getParameter("color");
		System.out.println(Accessories[0]+"  "+tagLine+" "+pocket+"  "+color);
		out.println("<html>");
		out.println("<head><title>T-shirt</title></head>");
		out.println("<body>");
		try {
            Statement stmt;
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/tshirtdb", "root", "abcd");
            if (conn != null) {
            	stmt= conn.createStatement();
            	String query;
            	if(Accessories.length != 0 && tagLine!=null && pocket!=null && color!=null){
            		for(String option:Accessories){
            			accessories=accessories+" "+option;
            		}
            		query="insert into tshirts values("+null+",'"+tagLine+"','"+accessories+"','"+color+"','"+pocket+"');";
            		stmt.executeUpdate(query);
            	}
            	query="select * from tshirts;";
            	ResultSet rs =stmt.executeQuery(query);
            	out.println("<table border=1>");
        		out.println("<tr>");
        		out.print("<td>OrderNo</td>");
        		out.print("<td>T-shirt Accessories</td>");
        		out.print("<td>T-shirt tag-line</td>");
        		out.print("<td>T-shirt type</td>");
        		out.print("<td>T-shirt color</td>");
        		out.println("</tr>");
        		if(!rs.isBeforeFirst()){
        			out.print("<tr>");
					out.print("<td>100</td>");
					out.print("<td>NULL</td>");
					out.print("<td>NULL</td>");
					out.print("<td>NULL</td>");
					out.print("<td>NULL</td>");
					out.println("</tr>");
        		}
        		while(rs.next()){
        			out.println("<tr>");
            		out.print("<td>"+(rs.getInt(1)+100)+"</td>");
            		out.print("<td>"+rs.getString(2)+"</td>");
            		out.print("<td>"+rs.getString(3)+"</td>");
            		out.print("<td>"+rs.getString(4)+"</td>");
            		out.print("<td>"+rs.getString(5)+"</td>");
            		out.println("</tr>");
        		}
        		out.println("</table>");
        		out.println("<a href=\"index.jsp\">click here</a>");
        		out.println("</body></html>");
            }
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
}
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Insert
 */
@WebServlet("/Insert")
public class Insert extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out = response.getWriter();
        Connection conn = null;
        Statement stmt = null;
        try {
            String driver = "com.mysql.jdbc.Driver";
            String url = "jdbc:mysql://localhost:3306/onlinedirectory";
            String username = "root";
            String password = "abcd";
            Class.forName(driver);
            conn = DriverManager.getConnection(url, username, password);
            stmt = conn.createStatement();
            String name = request.getParameter("name");
            String contact = request.getParameter("phone");
            String address = request.getParameter("address");
            String company = request.getParameter("company");
            int pin = Integer.parseInt(request.getParameter("pin"));

            stmt.executeUpdate("insert into tele_dir values('" + contact + "','" + name + "','" + address + "','" + company + "'," + pin + ");");
            
            out.println("The following contact details has been successfully updated");
            out.println("<br>Name: "+name+"<br>Phone No.:"+contact+"<br>Address:"+address+"<br>Company:"+company+"<br>Pin code:"+pin);
        } catch (Exception e) {
            out.println("Error");
            e.printStackTrace();
        } finally {
            try {
                stmt.close();
                conn.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
	}

}

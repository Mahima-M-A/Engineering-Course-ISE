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
 * Servlet implementation class JavaConnection
 */
@WebServlet("/Search")
public class Search extends HttpServlet {
	private static final long serialVersionUID = 1L;
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out = response.getWriter();
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;               
        try {
        	String driver = "com.mysql.jdbc.Driver";
	        String url = "jdbc:mysql://localhost:3306/onlinedirectory";
	        String username = "root";
	        String password = "abcd";
	        Class.forName(driver);
	        conn = DriverManager.getConnection(url, username, password);
            stmt = conn.createStatement();   
            String inp = request.getParameter("input");
            try {
	            rs = stmt.executeQuery("SELECT * FROM tele_dir where phno='"+inp+"'");
	            if(!rs.next()) {
	            	rs = stmt.executeQuery("SELECT * FROM tele_dir where name='"+inp+"'");
	            }
	            else {
	            	rs.beforeFirst();
	            }
            }
            catch(Exception e) {
                e.printStackTrace(); 
            }
            if(rs.next()) {
                String contact = rs.getString(1);
                String name = rs.getString(2);
                String address = rs.getString(3);
                String company = rs.getString(4);
                int pin = rs.getInt(5);
                out.println("Contact details:<br>Name: "+name+"<br>Phone No.:"+contact+"<br>Address:"+address+"<br>Company:"+company+"<br>Pin code:"+pin);
            } 
            else {
                out.println("No contact found");
            } 
            
        } catch (Exception e) {
            out.println("Error");
            e.printStackTrace();
        } 
    
    finally {
        try {
            stmt.close();
            conn.close();        
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
	}

}

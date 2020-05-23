import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class EditServlet
 */
@WebServlet("/EditServlet")
public class EditServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		out.println("<h1>Update Patient Details</h1>");
		int id=Integer.parseInt(request.getParameter("id"));
		
		Patient e=PatientDao.getPatientById(id);
		
		out.print("<form action='EditServlet2' method='post'>");
		out.print("<table>");
		out.print("<tr><td></td><td><input type='hidden' name='id' value='"+e.getId()+"'/></td></tr>");
		out.print("<tr><td>Name:</td><td><input type='text' name='name' value='"+e.getName()+"'/></td></tr>");
		out.print("<tr><td>Age:</td><td><input type='number' name='age' value='"+e.getAge()+"'/></td></tr>");
		out.print("<tr><td>Date of Admission:</td><td><input type='date' name='date' value='"+e.getDate()+"'/></td></tr>");
		out.print("<tr><td>Cause of Admission:</td><td><input type='text' name='cause' value='"+e.getCause()+"'/></td></tr>");
		out.print("<tr><td>Treatment proposed:</td><td><input type='text' name='treatment' value='"+e.getTreatment()+"'/></td></tr>");
		out.print("</td></tr>");
		out.print("<tr><td colspan='2'><input type='submit' value='Edit &amp; Save '/></td></tr>");
		out.print("</table>");
		out.print("</form>");
		
		out.close();
	}
}

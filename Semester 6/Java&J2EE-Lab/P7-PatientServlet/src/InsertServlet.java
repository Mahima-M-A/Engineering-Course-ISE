import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class InsertServlet
 */
@WebServlet("/InsertServlet")
public class InsertServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out=response.getWriter();
		
		String name=request.getParameter("name");
		int age=Integer.parseInt(request.getParameter("age"));
		String date=request.getParameter("date");
		String cause=request.getParameter("cause");
		String doctor=request.getParameter("doctor");
		String treatment=request.getParameter("treatment");
		
		Patient ob=new Patient();
		ob.setName(name);
		ob.setAge(age);
		ob.setDate(date);
		ob.setCause(cause);
		ob.setDoctor(doctor);
		ob.setTreatment(treatment);
		
		int status=PatientDao.save(ob);
		if(status>0){
			out.print("<p>Record saved successfully!</p>");
			request.getRequestDispatcher("index.html").include(request, response);
		}else{
			out.println("Unable to save record");
		}
		
		out.close();
	}

}

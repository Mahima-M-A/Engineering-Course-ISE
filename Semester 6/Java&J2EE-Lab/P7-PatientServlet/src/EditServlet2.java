import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class EditServlet2
 */
@WebServlet("/EditServlet2")
public class EditServlet2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		
		int id=Integer.parseInt(request.getParameter("id"));
		String name=request.getParameter("name");
		int age=Integer.parseInt(request.getParameter("age"));
		String date=request.getParameter("date");
		String cause=request.getParameter("cause");
		String doctor=request.getParameter("doctor");
		String treatment=request.getParameter("treatment");
		
		Patient ob=new Patient();
		ob.setId(id);
		ob.setName(name);
		ob.setAge(age);
		ob.setDate(date);
		ob.setCause(cause);
		ob.setDoctor(doctor);
		ob.setTreatment(treatment);
		
		int status=PatientDao.update(ob);
		if(status>0){
			response.sendRedirect("ViewServlet");
		}else{
			out.println("Sorry! unable to update record");
		}
		
		out.close();
	}

}

import java.util.*;
import java.sql.*;

public class PatientDao {
	public static Connection getConnection(){
		Connection con=null;
		try{
			Class.forName("com.mysql.jdbc.Driver");
			con=DriverManager.getConnection("jdbc:mysql://localhost:3306/people", "root", "abcd");
		}catch(Exception e){System.out.println(e);}
		return con;
	}
	public static int save(Patient e){
		int status=0;
		try{
			Connection con=PatientDao.getConnection();
			PreparedStatement ps=con.prepareStatement("insert into patientdb(name,age,dateOfAdmission,cause,doctor,treatment) values (?,?,?,?,?,?)");
			ps.setString(1,e.getName());
			ps.setInt(2,e.getAge());
			ps.setString(3,e.getDate());
			ps.setString(4,e.getCause());
			ps.setString(5,e.getDoctor());
			ps.setString(6,e.getTreatment());
			
			status=ps.executeUpdate();
			
			con.close();
		}catch(Exception ex){ex.printStackTrace();}
		
		return status;
	}
	public static int update(Patient e){
		int status=0;
		try{
			Connection con=PatientDao.getConnection();
			PreparedStatement ps=con.prepareStatement("update patientdb set name=?,age=?,dateOfAdmission=?,cause=?,doctor=?,treatment=? where id=?");
			ps.setString(1,e.getName());
			ps.setInt(2,e.getAge());
			ps.setString(3,e.getDate());
			ps.setString(4,e.getCause());
			ps.setString(5,e.getDoctor());
			ps.setString(6,e.getTreatment());
			ps.setInt(7,e.getId());
			
			status=ps.executeUpdate();
			con.close();
		}catch(Exception ex){ex.printStackTrace();}
		
		return status;
	}
	public static int delete(int id){
		int status=0;
		try{
			Connection con=PatientDao.getConnection();
			PreparedStatement ps=con.prepareStatement("delete from patientdb where id=?");
			ps.setInt(1,id);
			status=ps.executeUpdate();
			
			con.close();
		}catch(Exception e){e.printStackTrace();}
		
		return status;
	}
	public static Patient getPatientById(int id){
		Patient e=new Patient();
		
		try{
			Connection con=PatientDao.getConnection();
			PreparedStatement ps=con.prepareStatement("select * from patientdb where id=?");
			ps.setInt(1,id);
			ResultSet rs=ps.executeQuery();
			if(rs.next()){
				e.setId(rs.getInt(1));
				e.setName(rs.getString(2));
				e.setAge(rs.getInt(3));
				e.setDate(rs.getString(4));
				e.setCause(rs.getString(5));
				e.setDoctor(rs.getString(6));
				e.setTreatment(rs.getString(7));
			}
			con.close();
		}catch(Exception ex){ex.printStackTrace();}
		
		return e;
	}
	public static List<Patient> getAllPatients(){
		List<Patient> list=new ArrayList<Patient>();
		
		try{
			Connection con=PatientDao.getConnection();
			PreparedStatement ps=con.prepareStatement("select * from patientdb");
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				Patient e=new Patient();
				e.setId(rs.getInt(1));
				e.setName(rs.getString(2));
				e.setAge(rs.getInt(3));
				e.setDate(rs.getString(4));
				e.setCause(rs.getString(5));
				e.setDoctor(rs.getString(6));
				e.setTreatment(rs.getString(7));
				list.add(e);
			}
			con.close();
		}catch(Exception e){e.printStackTrace();}
		
		return list;
	}
}

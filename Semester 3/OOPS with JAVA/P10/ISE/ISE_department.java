package ISE;
import Dept.*;
import java.util.Scanner;
class AgeException extends Exception //user defined exception
{
    AgeException(String str)
    {
        super(str);
    }
    void myException(String msg)
    {
        System.out.println(msg);
    }
}
public class ISE_department implements Department
{
    Faculty[] ob; //creating an array of objects of class Faculty
    
    public void readdata() //defining readdata() of interface Department
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the total number of employees:");
        int n=sc.nextInt();
        ob=new Faculty[n];
        for(int i=0;i<n;i++)
        {
            ob[i]=new Faculty();
            System.out.println("Faculty["+(i+1)+"] details:");
            System.out.println("Enter Name:");
            sc.nextLine();
            ob[i].name=sc.nextLine();
            System.out.println("Enter Age:");
            int tempage=sc.nextInt();
            try
            {
                if(tempage>58)
                {
                    throw new AgeException("AgeException");
                }
                else
                    ob[i].age=tempage;
            }
            catch(AgeException e)
            {
                System.out.println(e);
            }
            
            System.out.println("Enter Designation:");
            sc.nextLine();
            ob[i].designation=sc.nextLine();
            System.out.println("Enter years of experience:");
            ob[i].years_of_experience=sc.nextInt();
            System.out.println("Enter joining date:");
            sc.nextLine();
            ob[i].joining_date=sc.nextLine();
            System.out.println("Enter subjects handled:");
            ob[i].subjects_handled=sc.nextLine();
        }
    }
    
    public void printdata() //defining printdata() of interface Department
    {
        for(int i=0;i<ob.length;i++)
        {
            if(ob[i].years_of_experience>=20) //to check if the faculty's experience is more than 19 or not
            {
                System.out.println("NAME: "+ob[i].name);
                System.out.println("AGE: "+ob[i].age);
                System.out.println("DESIGNATION: "+ob[i].designation);
                System.out.println("YEARS OF EXPERIENCE: "+ob[i].years_of_experience);
                System.out.println("JOINING DATE: "+ob[i].joining_date);
                System.out.println("SUBJECTS HANDLED: "+ob[i].subjects_handled);
            }
        }
    }
}

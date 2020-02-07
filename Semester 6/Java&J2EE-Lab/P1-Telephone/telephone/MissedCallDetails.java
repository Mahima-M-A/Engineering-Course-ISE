package telephone;
import java.util.Calendar;

public class MissedCallDetails{
    public Calendar calObj;
    public String name;
    public int phno;

    public MissedCallDetails(Calendar calObj,String name,int phno){ //to initialize the class members
        this.calObj=calObj;
        this.name=name;
        this.phno=phno;
    }

    public void displayMissedCall(){ //to display the missed call details
        System.out.println("\nPhone number: "+phno);
        System.out.println("Contact name: "+name);
        System.out.println("Time of call: "+calObj.getTime());
    }
}
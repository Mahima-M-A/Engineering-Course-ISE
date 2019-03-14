package ResultPackage;
import StudentPackage.*;

class sgpaLimit extends Exception //user defined exception
{
    sgpaLimit(String msg)
    {
        super(msg);
    }
    void limit(String msg)
    {
        System.out.println(msg);
    }
}

class Result
{
    public static void main(String[] args)
    {
        float cgpa=0;
        RegisterStudent ob[]=new RegisterStudent[4]; //creates an array of objects of RegisterStudent class
        RegisterStudent obj=new RegisterStudent(); //creates an object of RegisterStudent class
        obj.getDetails();
        for(int i=0;i<4;i++)
        {
            System.out.println("\nSemester["+(i+1)+"]:");
            ob[i]=new RegisterStudent();
            ob[i].getMarks();
            float sgpaT=ob[i].sgpa_cal();
            float sgpa=0;
            try
            {
                if(sgpaT>10)
                    throw new sgpaLimit("Not possible");
                else
                    sgpa=sgpaT;
            }
            catch(sgpaLimit sl)
            {
                System.out.println(sl);
            }
            obj.printDetails();
            ob[i].print_credit_grade();
            ob[i].print();
            System.out.println("SGPA="+sgpa);
            cgpa+=sgpa;
        }
        
        System.out.println("CGPA="+cgpa/4);
    }
}

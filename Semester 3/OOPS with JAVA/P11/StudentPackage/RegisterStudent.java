package StudentPackage;
import java.util.Scanner;

class CreditLimit extends Exception //user defined exception
{
    CreditLimit(String msg)
    {
        super(msg);
    }
    void cred_lim(String msg)
    {
        System.out.println(msg);
    }
}

public class RegisterStudent implements Student
{
    float sgpa=0;
    int credits=0,ct=0,c,cr=0;
    int marks[];
    int cre[];
    String grade[];
    String name,branch;
    
    Scanner sc=new Scanner(System.in);
    
    //defines getDetails() of the interface Student
    public void getDetails() //inputs the details of the student 
    {
        System.out.println("Enter name:");
        name=sc.nextLine();
        System.out.println("Enter your branch:");
        branch=sc.nextLine();
    }
    
    public void printDetails() //displays the details of the student
    {
        System.out.println("NAME: "+name);
        System.out.println("BRANCH: "+branch);
    }
    
    public void print() //displays the total credits registered and obtained in that semester
    {
        System.out.println("CREDITS registered for: "+credits);
        System.out.println("CREDITS obtained: "+cr);
    }
    
    public void getMarks() //inputs number of credits and subjects registered marks obtained in each subject in that semester
    {
        System.out.println("Enter the number of credits registered for in this sem:");
        int c=sc.nextInt();
        try
        {
            if(c>30)
                throw new CreditLimit("Exceeding credit limit");
            else
                credits=c;
        }
        catch(CreditLimit cl)
        {
            System.out.println(cl);
            
        }
        System.out.println("Enter the number of subjects registered for:");
        int n=sc.nextInt();
        if(n>7)
        {
            System.out.println("Cannot register for more than 7 subjects");
            System.out.println("Enter the number of subjects registered for:");
            n=sc.nextInt();
        }
        marks=new int[n];
        cre=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter marks obtained in subject["+(i+1)+"] and credits alloted for it:");
            marks[i]=sc.nextInt();
            cre[i]=sc.nextInt();
            ct+=cre[i];
            if(cre[i]>credits || ct>credits)
            {
                System.out.println("Enter the credits alloted correctly");
                i=-1;
            }
        }
    }
    
    public void print_credit_grade() //displays credits and grade obtained in each subject of that semester
    {
        for(int i=0;i<cre.length;i++)
        {
            System.out.println("Subject["+(i+1)+"]-  CREDITS OBTAINED: "+cre[i]+"  GRADE: "+grade[i]);
        }
    }
    
    public float sgpa_cal() //calculates sgpa of that semester 
    {
        grade=new String[cre.length];
        for(int i=0;i<cre.length;i++)
        {
            if(marks[i]>=90)
            {
                sgpa+=cre[i]*10;
                grade[i]="S+";
            }
            else if(marks[i]>=80)
            {
                sgpa+=cre[i]*9;
                grade[i]="S";
            }
            else if(marks[i]>=70)
            {
                sgpa+=cre[i]*8;
                grade[i]="A";
            }
            else if(marks[i]>=60)
            {
                sgpa+=cre[i]*7;
                grade[i]="B";
            }
            else if(marks[i]>=50)
            {
                sgpa+=cre[i]*6;
                grade[i]="C";
            }
            else if(marks[i]>=45)
            {
                sgpa+=cre[i]*5;
                grade[i]="D";
            }
            else if(marks[i]>=40)
            {
                sgpa+=cre[i]*4;
                grade[i]="E";
            }
            else
            {
                sgpa+=0;
                cre[i]=0;
                grade[i]="F";
            }
            cr+=cre[i];
        }
        sgpa/=credits;
        return sgpa;
    }
}

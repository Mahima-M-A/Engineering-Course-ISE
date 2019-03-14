/*Program to create a Personal class to take in an employees details and calculate his/her salary,tax to be paid,eligibility to get a
promotion and loan(s)*/

import java.util.Scanner;
class P07_Personal
{
    String name,edu;
    int age,num_loans,experience;
    float loan_amt[]=new float[3];
    float sal,da,hra,basic,tax;
    
    Personal() //to initialize salary and tax
    {
        sal=0;
        tax=0;
    }
    void details() //to input the employees details
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter name:");
        name=sc.nextLine();
        System.out.println("Enter age:");
        age=sc.nextInt();
        System.out.println("Enter education:");
        sc.nextLine();
        edu=sc.nextLine();
        System.out.println("Enter experience:");
        experience=sc.nextInt();
        System.out.println("Enter basic salary,da,hra:");
        basic=sc.nextFloat();
        da=sc.nextFloat();
        hra=sc.nextFloat();
        System.out.println("Enter no. of loans required(max 3):");
        num_loans=sc.nextInt();
        if(num_loans>3)
            System.out.println("Cannot take more than 3 loans");
        else
        {
            for(int i=0;i<num_loans;i++)
            {
                System.out.println("Enter loan amt["+(i+1)+"]:");
                loan_amt[i]=sc.nextFloat();
            }
        }
    }
    
    void sal_cal() //to calculate total salary amount
    {
        sal=da+hra+basic;
    }
    
    void taxPay() //to calculate tax amount to be paid
    {
        if(sal<250000)
            tax=0;
        else if(sal<500000)
            tax=(sal-250000)*5/100;
        else if(sal<1000000)
            tax=(sal-500000)*20/100+250000*5/100;
        else
            tax=(sal-1000000)*30/100+500000*20/100+250000*5/100;
    }
    
    boolean isEligible() //to check for eligibility to get loan(s)
    {
        if(experience>2 && age>21 && (sal/12)>15000)
            return true;
        else
            return false;
    }
    
    boolean isEligiblePromotion() //to check for eligibility to get a promotion
    {
        if(experience>=3)
            return true;
        else
            return false;
    }
    
    void display(boolean eli1,boolean eli2) //to display the employees details
    {
        System.out.println("Name:"+name);
        System.out.println("Age:"+age);
        System.out.println("Education:"+edu);
        System.out.println("Salary:"+sal);
        System.out.println("Tax to be paid:Rs."+tax);
        
        if(eli1)
        {
            System.out.println("Eligble for loan");
            System.out.println("Number of loans requested for:"+num_loans);
            for(int i=0;i<num_loans;i++)
                System.out.println("Loan Amount["+(i+1)+"]:Rs."+loan_amt[i]);
        }
        else
            System.out.println("Not eligible for loan");
            
        if(eli2)
            System.out.println("Eligible for promotion");
        else
            System.out.println("Not eligible for promotion");
    }
    
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no. of employees:");
        int n=sc.nextInt();
        P07_Personal[] ob=new P07_Personal[n]; //creating an array of objects of class personal for 'n' employees
        for(int i=0;i<n;i++)
        {
            ob[i]=new P07_Personal();
            System.out.println("Employee["+(i+1)+"]:");
            ob[i].details(); //getting details of each employee
            ob[i].sal_cal(); //caalculating salary of each employee
            boolean eli1=ob[i].isEligible(); //checking for eligibilty to get a loan of each employee
            boolean eli2=ob[i].isEligiblePromotion(); //checking for eligibilty to get a promotion of each employee
            ob[i].taxPay(); //calculating tax to be paid of each employee
            ob[i].display(eli1, eli2); //displaying details of each employee
        }
    }
}

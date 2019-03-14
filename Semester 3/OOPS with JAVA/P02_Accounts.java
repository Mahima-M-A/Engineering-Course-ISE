//Program to 'n' accounts with operations(Deposit, Withdraw)

import java.util.Scanner;
class P02_Accounts
{
    Scanner sc=new Scanner(System.in);
    int Accno;
    String name;
    long Phone_No;
    float balance_amt;
    void getinput() //to get the details of each account holder
    {
        System.out.println("Enter your name:");
        name=sc.next();
        System.out.println("Enter your account number:");
        Accno=sc.nextInt();
        System.out.println("Enter your phone number:");
        Phone_No=sc.nextLong();
        System.out.println("Enter your current balance amount:");
        balance_amt=sc.nextFloat();
    }
    void deposit() //to deposit an amt
    {
        System.out.println("Enter the amount to be deposited:");
        float amt=sc.nextFloat();
        balance_amt+=amt;
    }
    void withdraw() //to withdraw an amt
    {
        System.out.println("Enter the amount to be withdrawn:");
        float amt=sc.nextFloat();
        if(balance_amt>=amt)
            balance_amt-=amt;
        else
            System.out.println("There's not enough balance to withdraw Rs."+amt);
    }
    void print() //to print the details of each account holder
    {
        System.out.println("\nDetails:");
        System.out.println("Name:"+name);
        System.out.println("Account Number:"+Accno);
        System.out.println("Phone Number:"+Phone_No);
        System.out.println("Balance_Amount:Rs."+balance_amt);
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of people:");
        int n=sc.nextInt();
        Account ob[]=new Account[n];  //creating array of objects of Account class for 'n' people
        for(int i=0;i<n;i++)
        {
            ob[i]=new Account();
            System.out.println("Person["+(i+1)+"]:");
            ob[i].getinput();
            while(true)
            {
                System.out.println("Menu:\n1.Deposit\n2.Withdraw\n3.exit\nEnter choice:");
                int ch=sc.nextInt();
                if(ch==1)
                {
                    ob[i].deposit();
                    ob[i].print();
                }
                else if(ch==2)
                {
                    if(ob[i].balance_amt>0)
                        ob[i].withdraw();
                    else
                        System.out.println("Couldn't withdraw as balance amount is Rs.0!");
                    ob[i].print();
                }
                else if(ch==3)
                    break;
                else
                    System.out.println("Invalid choice!");
            }
        }
    }
}

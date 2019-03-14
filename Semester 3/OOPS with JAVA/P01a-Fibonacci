//Program to generate a fibonacci series of 'n' numbers

import java.util.Scanner;
class Fibonacci
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the value of n:");
        int n=sc.nextInt();
        int f=0,s=1,t;
        if(n==0) //no numbers in the series
        {
            System.out.println("Error!");
            System.exit(0);
        }
        else if(n==1) //one number in the series
        {
            System.out.println("Fibonacci Series:");
            System.out.println(f);
        }
        else if(n==2) //two numbers in the series
        {
            System.out.println("Fibonacci Series:");
            System.out.println(f);
            System.out.println(s);
        }
        else //more than 2 numbers in the series
        {
            System.out.println("Fibonacci Series:");
            System.out.println(f);
            System.out.println(s);
            for(int i=2;i<n;i++)
            {
                t=f+s;
                System.out.println(t);
                f=s;
                s=t;
            }
        }
    }
}

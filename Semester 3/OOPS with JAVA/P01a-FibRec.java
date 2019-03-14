//Program to generate a fibonacci series of 'n' numbers using recursion

import java.util.Scanner;
class FibRec
{
    int fib(int n) //to generate fibonacci series
    {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else
            return fib(n-2)+fib(n-1);
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter value  n:");
        int n=sc.nextInt();
        FibRec ob=new FibRec();
        if(n==0) //no numbers in the series
        {
            System.out.println("Error!");
            System.exit(0);
        }
        System.out.println("Fibonacci Series:");
        for(int i=0;i<n;i++)
        {
            System.out.println(ob.fib(i));
        }
    }
}

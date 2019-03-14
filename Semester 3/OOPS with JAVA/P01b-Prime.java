//Program to check if it is a prime number or not

import java.util.Scanner;
class Prime
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number:");
        int n=sc.nextInt();
        int count=0;
        for(int i=2;i<=n/2;i++)
            if(n%i==0)
                count++; //counts the number of factors between 2 and n/2 
        if(count!=0)
            System.out.println(n+" is not a prime number");
        else
            System.out.println(n+" is a prime number");
    }
}

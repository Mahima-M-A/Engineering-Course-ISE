//Program to implement bubble sort 

import java.util.Scanner;
class P01c_BubbleSort
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the array size:");
        int n=sc.nextInt();
        int a[]=new int[n];
        
        System.out.println("Enter "+n+" numbers:");
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                if(a[j]>a[j+1])
                {
                    int temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                }
        System.out.println("Sorted array:");
        for(int i=0;i<n;i++)
            System.out.println(a[i]);
    }
}

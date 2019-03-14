//Program to perform multiplication of 2 matrices by passing objects as parameters

import java.util.Scanner;
class Mul
{
    Scanner sc=new Scanner(System.in);
    int m,n;
    int a[][];
    Mul(int m,int n) //to initialize number of rows and columns of a matrix
    {
        this.m=m;
        this.n=n;
        a=new int[m][n]; 
    }
    void compute(Mul ob,Mul obj) //to multiply 2 matrices
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<ob.n;j++)
                for(int k=0;k<n;k++)
                    obj.a[i][j]+=a[i][k]*ob.a[k][j];
    }
    void accept() //to input elements of a matrix
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                a[i][j]=sc.nextInt();
    }
    void print() //to display a matrix
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                System.out.print(a[i][j]+" ");
            System.out.println();
        }
    }
}
class MatMul
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the order of matrix1(mxn):");
        int m=sc.nextInt();
        int n=sc.nextInt();
        System.out.println("Enter the order of matrix2(pxq):");
        int p=sc.nextInt();
        int q=sc.nextInt();
        if(n!=p) //to check if matrix multiplication is possible or not by checking if number of columns of matrix1 is equal to number of rows of matrix2
            System.out.println("Matrix multiplication not possible!");
        else
        {
            Mul ob1=new Mul(m,n);
            System.out.println("Enter "+(m*n)+" elements of matrix1:");
            ob1.accept(); //to input matrix1
            Mul ob2=new Mul(p,q);
            System.out.println("Enter "+(p*q)+" elements of matrix2:");
            ob2.accept(); //to input matrix2
            Mul ob3=new Mul(m,q);
            ob1.compute(ob2,ob3); //to multiply matrix1 and matrix2
            System.out.println("Matrix1:");
            ob1.print(); //to display matrix1
            System.out.println("*");
            System.out.println("Matrix2:");
            ob2.print(); //to display matrix2
            System.out.println("=");
            System.out.println("Product Matrix:");
            ob3.print(); //to display the product matrix
        }
    }
}

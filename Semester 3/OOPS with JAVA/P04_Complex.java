//Program to perform addition,subtraction and multiplication of 2 complex numbers

import java.util.Scanner;
class P04_Complex
{
    float real1,img1,real2,img2,ans_r,ans_i;
    Complex()
    {
        ans_r=0;
        ans_i=0;
    }
    Complex(float real1,float img1,float real2,float img2) //to initialize the complex numbers
    {
        this.real1=real1;
        this.real2=real2;
        this.img1=img1;
        this.img2=img2;
    }
    void add() //to add 2 complex numbers
    {
        ans_r=real1+real2;
        ans_i=img1+img2;
        System.out.println("("+real1+"+("+img1+"i))+("+real2+"+("+img2+"i))=("+ans_r+"+("+ans_i+"i))");
    }
    void subtract() //to subtract 2 complex numbers
    {
        ans_r=real1-real2;
        ans_i=img1-img2;
        System.out.println("("+real1+"+("+img1+"i))-("+real2+"+("+img2+"i))=("+ans_r+"+("+ans_i+"i))");
    }
    void multiply() //to multiply 2 complex numbers
    {
        ans_r=real1*real2+img1*img2;
        ans_i=real1*img2+real2*img1;
        System.out.println("("+real1+"+("+img1+"i))*("+real2+"+("+img2+"i))=("+ans_r+"+("+ans_i+"i))");
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Complex ob=new Complex();
        System.out.println("Enter the real and imaginary parts of first complex number:");
        ob.real1=sc.nextFloat();
        ob.img1=sc.nextFloat();
        System.out.println("Enter the real and imaginary parts of second complex number:");
        ob.real2=sc.nextFloat();
        ob.img2=sc.nextFloat();
        Complex ob1=new Complex(ob.real1,ob.img1,ob.real2,ob.img2);
        ob1.add();
        ob1.subtract();
        ob1.multiply();
    }
}

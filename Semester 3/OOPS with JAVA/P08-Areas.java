//Program to create a class Circle and use its variables in classes sector and segment using inheritance

import java.util.Scanner;
class Circle //Base class
{
    double radius;
    Circle(double radius) //initializes radius of circle
    {
        this.radius=radius;
    }
    double area() //returns area of circle
    {
        return 3.14*radius*radius;
    }
}

class Sector extends Circle
{
    double r,angle;
    Sector(double rad,double angle) 
    {
        super(rad); //initializes radius of circle
        r=radius; //uses radius of class Circle(base class) 
        this.angle=(3.14/180)*angle; //initializes angle of sector
    }
    double areaS() //returns area of sector
    {
        System.out.println("In sector function");
        System.out.println("Area of circle:"+area()); //calls area() of base class 
        double area=0.5*r*r*angle;
        return area;
    }
}

class Segment extends Circle
{
    double r,angle,h;
    Segment(double rad,double h)
    {
        super(rad); //initializes radius of circle
        r=radius; //uses radius of class Circle(base class) 
        this.h=h; //initializes length of segment
        this.angle=Math.acos((r-h)/r); 
    }
    double areaSeg() //returns area of segment
    {
        System.out.println("In segment function");
        System.out.println("Area of circle:"+area()); //calls area() of base class 
        double area=r*r*angle-(r-h)*Math.pow((2*r*h-h*h), 0.5);
        return area;
    }
}

class Areas
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the radius:");
        double r=sc.nextDouble();
        System.out.println("Enter the angle of sector:");
        double ang=sc.nextDouble();
        Sector ob1=new Sector(r,ang);
        System.out.println("Enter the length of segment:");
        double h=sc.nextDouble();
        Segment ob2=new Segment(r,h);
        System.out.println("Area of sector:"+ob1.areaS()); //calls area() of sector class 
        System.out.println("Area of segment:"+ob2.areaSeg()); //calls area() of segment class 
    }
}

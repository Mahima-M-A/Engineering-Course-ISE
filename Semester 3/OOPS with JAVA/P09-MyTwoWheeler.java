//Program to illustrate inheritance

abstract class Vehicle
{
    int year;
    Vehicle()
    {
        System.out.println("Vehicle constructor");
    }
    abstract void getData();
    abstract void putData();
}

class TwoWheeler extends Vehicle
{
    String name;
    TwoWheeler()
    {
        System.out.println("Two wheeler constructor");
    }
    void getData() //defines getData() of abstract class
    {
        name="TVS";
        year=2000;
    }
    void putData() //defines putData() of abstract class
    {
        System.out.println("Year of manufacture:"+year);
    }
}

final class FourWheeler extends Vehicle //cannot be inherited
{
    String name;
    FourWheeler()
    {
        System.out.println("Four wheeler constructor");
    }
    void getData() //defines getData() of abstract class
    {
        name="CAR";
        year=2010;
    }
    void putData() //defines putData() of abstract class
    {
        System.out.println("Vehicle name:"+name);
        System.out.println("Year of manufacture:"+year);
    }
}

class MyTwoWheeler extends TwoWheeler
{
    String name;
    MyTwoWheeler()
    {
        System.out.println("My two wheeler constructor");
    }
    String getName()
    {
        name=super.name; //uses 'name' of TwoWheeler(base class)
        return name;
    }
    public static void main(String[] args)
    {
        MyTwoWheeler ob=new MyTwoWheeler(); //creating object of MyTwoWheeler class
        ob.getData();
        ob.putData();
        System.out.println("Name:"+ob.getName()); //
    }
}

//Program to implement stack data structure using an array

import java.util.Scanner;
class Stack
{
    int top,size;
    String stack[]; //creates an array of strings
    Stack()
    {
        top=-1; //points to the top end of the stack
        size=5; //indicates the stack size
        stack=new String[size];
    }
    void push(String element) //pushes a string into the stack at the rear end
    {
        if(top==size-1)
            System.out.println("Stack overflow!");
        else
        {
            stack[++top]=element;
            System.out.println(element+" is pushed");
        }
    }
    void pop() //pops out a string from the stack at the rear end
    {
        if(top==-1)
            System.out.println("Stack underflow!");
        else
        {
            String data=stack[top--];
            System.out.println("Popped element:"+data);
        }
    }
    void display() //displays the contents of the stack
    {
        if(top==-1)
            System.out.println("Stack is empty!");
        else
        {
            System.out.println("Stack contains:");
            for(int i=0;i<=top;i++)
                System.out.println(stack[i]);
        }
    }
}

class P03_StackImplement
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        Stack ob=new Stack(); //creating an object of the stack class
        while(true)
        {
            System.out.println("Menu:\n1.Push\n2.Pop\n3.Display\n4.exit\nEnter choice:");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.println("Enter the element to be pushed:");
                    String ele=sc.next();
                    ob.push(ele);
                    break;
                case 2:
                    ob.pop();
                    break;
                case 3:
                    ob.display();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!");
                    
            }
        }
    }
}

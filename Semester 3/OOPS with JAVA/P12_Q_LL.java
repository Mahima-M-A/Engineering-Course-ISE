//Program to illustrate the use of collection framework of java (ArrayList and LinkedList)

import java.util.*;
class P12_Q_LL
{
    static void q() //to implement queue data structure using ArrayList
    {
        int flag=1;
        Scanner sc=new Scanner(System.in);
        ArrayList<String> Q=new ArrayList<>();
        while(flag!=0)
        {
            System.out.println("1.Enqueue\n2.Dequeue\n3.Display\n-1.Exit\nEnter choice:");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.println("Enter a string:");
                    sc.nextLine();
                    String str=sc.nextLine();
                    Q.add(Q.size(),str); //adds a string at the rear end of the Q
                    System.out.println("Enqueued element:"+str);
                    break;
                case 2:
                    if(Q.isEmpty())
                        System.out.println("Queue is empty");
                    else
                        System.out.println("Dequeued element:"+Q.remove(0)); //removes a string from the front end of the Q
                    break;
                case 3:
                    if(Q.isEmpty())
                        System.out.println("Queue is empty");
                    else
                    {
                        System.out.println("Queue contains:");
                        for(int i=0;i<Q.size();i++) //to display the contents of the Q
                            System.out.println(Q.get(i));
                    }
                    break;
                case -1: flag=0;
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
    
    static void ll() //to implement linked list data structure using LinkedList
    {
        Scanner sc=new Scanner(System.in);
        LinkedList<String> ll=new LinkedList<>();
        while(true)
        {
            System.out.println("Enter a string(else -1 to quit):");
            String str=sc.nextLine();
            if(str.equals("-1"))
                break;
            ll.add(str); //adds a string to each node of linked list
        }
        ListIterator LIter=ll.listIterator(); //iterator to iterate through the list
        System.out.println("Contents of the list with length<5");
        while(LIter.hasNext()) //loop to iter through the list
        {
            String s=(String)LIter.next();
            if(s.length()<5) //to check if the length of string in each node if its length is less than 5 or not
                System.out.println(s);
        }
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        while(true)
        {
            System.out.println("1.Queue implementation\n2.Linked list implementation\n-1.exit\nEnter choice:");
            int ch=sc.nextInt();
            switch(ch)
            {
                case 1: q(); //calls q()
                    break;
                case 2: ll(); //calls ll()
                    break;
                case -1: System.exit(0);
                default: System.out.println("Invalid choice!");
            }
        }
    }
}

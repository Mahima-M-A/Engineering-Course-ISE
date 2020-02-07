package telephone;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class DataBaseCallers{
    public static HashMap<Integer,String> phList; //declare a hashmap
    public static Scanner sc=new Scanner(System.in);

    public static void holdCallersData(){ //inputs the contact details to be stored
        System.out.println("Enter how many entries you want to store:");
        int n=sc.nextInt();
        createEntries(n); //to create a contact
    }

    public static void createEntries(int n){
        phList=new HashMap<Integer,String>(); //initialze the hashmap
        for(int i=0;i<n;i++){
            System.out.println("Enter phone number and contact name:");
            int phno=sc.nextInt();
            String name=sc.next();
            phList.put(phno,name); //adds the contact to the hashmap
        }
    }

    public static void displayEntries(){
        System.out.println("\nEntries(Phone number - Name) stored:");
        for(Map.Entry entry: phList.entrySet()){ //to traverse the hashmap
            System.out.println(entry.getKey()+" - "+entry.getValue());
        }
    }
}
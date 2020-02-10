import telephone.*;
import java.util.LinkedList;
import java.util.Calendar;
import java.util.ListIterator;


public class CallManager{
    public static void handleMissedCallActivities(){
        LinkedList<MissedCallDetails> missedCalls=new LinkedList<MissedCallDetails>(); //List of type class MissedCallDetails
        ListIterator<MissedCallDetails> it; //declare an iterator
        while(true){
            System.out.println("\nMenu\n1. To add a missed call \n2. To display and delete on request \n3. To delete based on phone number \n4. To display all the missed call details\n5. To display the stored contact details\n-1. To exit\nEnter choice: ");
            int ch=DataBaseCallers.sc.nextInt();

            switch(ch){
                case 1:
                    System.out.println("\nEnter the missed call number:");
                    int phno=DataBaseCallers.sc.nextInt();
                    Calendar calObj=Calendar.getInstance(); //to get an instance of the Calendar class
                    String name;

                    if(DataBaseCallers.phList.containsKey(phno))
                        name=DataBaseCallers.phList.get(phno);
                    else
                        name="Private Caller";

                    MissedCallDetails mcall=new MissedCallDetails(calObj,name,phno);
                    if(missedCalls.size()==10) //to remove the oldest missed call once the list size reaches 10
                        missedCalls.removeLast();
                    missedCalls.addFirst(mcall);
                    break;
                
                case 2:
                    it=missedCalls.listIterator(); //initialize the iterator
                    int count=0; //to keep a count of the no. of missed calls
                    while(it.hasNext()){
                        count++;
                        System.out.println("Phone number: ");
                        MissedCallDetails m1=it.next();
                        System.out.print(m1.phno+"\n");

                        System.out.println("Do you want to:\n1. delete the details of this number\n2. move to the next missed call\n3. display the details of this number\n");
                        int cho = DataBaseCallers.sc.nextInt();
                        
                        if(cho==1){
                            int index=missedCalls.indexOf(m1);
                            missedCalls.remove(index); //or directly use - missedCalls.remove(m1);
                        }
                        else if(cho==2){
                            if(!it.hasNext()){
                                System.out.println("No more missed calls present");
                            }
                        }
                        else if(cho==3)
                            m1.displayMissedCall();
                    }
                    if(count==0){
                        System.out.println("No missed calls");
                    }
                    break;

                case 3:
                    System.out.println("Enter the missed call number whose details you want to delete:");
                    int pno=DataBaseCallers.sc.nextInt();
                    it=missedCalls.listIterator(); //initialize the iterator
                    count=0; //to keep a count of the no. of missed calls
                    boolean flag=false;
                    
                    while(it.hasNext()){
                        count++;
                        MissedCallDetails m1=it.next();
                        if(m1.phno==pno){
                            flag=true;
                            int index=missedCalls.indexOf(m1);
                            missedCalls.remove(index); //or directly use - missedCalls.remove(m1);
                            break;
                        }
                    }
                    if(count==0)
                        System.out.println("No missed calls");
                    else{
                        if(flag)
                            System.out.println("Phone number with details "+ pno +" deleted");
                        else
                            System.out.println("No such number exists");
                    }
                    break;
                
                case 4: //to display the missed call list using an iterator
                    it=missedCalls.listIterator(); //initialize the iterator
                    while(it.hasNext()){
                        MissedCallDetails m1=it.next();
                        m1.displayMissedCall(); //calls the function of MissedCallDetails to display the call details
                    }
                    break;
                
                case 5:
                    DataBaseCallers.displayEntries(); //calls the function of DataBaseCallers to display the stored contacts
                    break;
                
                case -1:
                    System.exit(0);
                
                default:
                    System.out.println("Invalid choice");
            }
        }
    }

    public static void main(String args[]){
        DataBaseCallers.holdCallersData(); //calls the function of DataBaseCallers to store the contacts
        handleMissedCallActivities();
    }
}

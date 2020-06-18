import decorator.*;
public class MainClass {

	public static void main(String[] args) {
		Sports ob;
		
		ob=new IndoorSports();
		System.out.println("Total Indoor Sports Stock:"+ob.getCurrentStock());
		ob=new Billiards(ob);
		System.out.println("Total Indoor Sports Stock:"+ob.getCurrentStock());
		ob=new Carrom(ob);
		System.out.println("Total Indoor Sports Stock:"+ob.getCurrentStock());
		ob=new Badminton(ob);
		System.out.println("Total Indoor Sports Stock:"+ob.getCurrentStock());
		
		ob=new OutdoorSports();
		System.out.println("\nTotal Outdoor Sports Stock:"+ob.getCurrentStock());
		ob=new Trekking(ob);
		System.out.println("Total Outdoor Sports Stock:"+ob.getCurrentStock());
		ob=new Cricket(ob);
		System.out.println("Total Outdoor Sports Stock:"+ob.getCurrentStock());
		ob=new LongJump(ob);
		System.out.println("Total Outdoor Sports Stock:"+ob.getCurrentStock());
	}
}
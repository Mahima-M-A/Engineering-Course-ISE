import template.OfflineOrder;
import template.OnlineOrder;
import template.OrderProcessing;

public class MainClass {
	public static void main(String[] args) {
		OrderProcessing ob;
		
		ob=new OnlineOrder();
		System.out.println("Online Mode");
		ob.purchaseItem();
		
		/*ob=new OfflineOrder();
		System.out.println("Offline Mode");
		ob.purchaseItem();*/
	}
}

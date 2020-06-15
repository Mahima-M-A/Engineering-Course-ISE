import observer.Customer;
import observer.Store;

public class MainClass {

	public static void main(String[] args) {
		Store s1 = new Store("Store1");
		Customer c1 = new Customer(s1, "C1");
		Customer c2 = new Customer(s1, "C2");
		
		s1.setDisPercent("Diwali", 20);
		
		s1.detach(c2);
		s1.setDisPercent("Dussehra", 15);
		
		Customer c3 = new Customer(s1, "C3");
		s1.setDisPercent("Ugadi", 12);

	}

}

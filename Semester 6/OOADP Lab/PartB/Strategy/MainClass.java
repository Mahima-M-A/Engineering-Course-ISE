import strategy.Customer;
import strategy.FirstTime;
import strategy.Regular;
import strategy.Senior;

public class MainClass {
	public static void main(String[] args) {
		Customer ob = new FirstTime("C1");
		ob.displayBill(500);
		ob = new Regular("C2");
		ob.displayBill(500);
		ob = new Senior("C3");
		ob.displayBill(500);
	}
}
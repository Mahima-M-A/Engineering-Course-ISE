import bridge.*;

public class MainClass {
	public static void main(String[] args) {
		Customer c = new FirstTime("C1", new Discount1());
		c.displayBill(500);
		c = new FirstTime("C2", new Discount2());
		c.displayBill(500);
		c = new Regular("C3", new Discount3());
		c.displayBill(500);
		c = new Senior("C4", new Discount4());
		c.displayBill(500);
	}
}

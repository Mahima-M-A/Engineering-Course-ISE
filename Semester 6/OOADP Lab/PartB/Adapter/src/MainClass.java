import adapter.*;

public class MainClass {
	public static void main(String[] args) {
		Item item = new Item("Milk", 2, 30.0);
		item.setTaxOb(new TaxAdapter());
		item.displayBill();
	}
}
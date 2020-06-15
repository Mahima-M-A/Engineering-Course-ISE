package adapter;

public class Item {
	String name;
	int qty;
	double amt;
	TaxCalculator ob;
	public Item(String name, int qty, double amt) {
		this.name = name;
		this.qty = qty;
		this.amt = amt;
	}
	public void setTaxOb(TaxCalculator ob) {
		this.ob = ob;
	}
	public void displayBill() {
		double tax = this.ob.calcTax(qty, amt);
		System.out.println("Item purchased: \nItem Name: "+name+"\nQuantity: "+qty+"\nPrice: "+amt+"\nTax amount: "+tax+"\nBill amount: "+(amt*qty+tax));
	}
}

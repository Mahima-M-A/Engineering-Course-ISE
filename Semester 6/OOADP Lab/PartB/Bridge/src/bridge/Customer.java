package bridge;

public abstract class Customer {
	String id, type;
	Discount disOb;
	public void displayBill(double amt) {
		double discount = disOb.calcDis(amt);
		System.out.println("\nCustomer id: "+id+"\nType: "+type+"\nItem Price: "+amt+"\nDiscount: "+discount+"\nBill amount: "+(amt-discount));
	}
}

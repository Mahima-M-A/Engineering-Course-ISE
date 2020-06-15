package bridge;

public class FirstTime extends Customer {
	public FirstTime(String id, Discount disOb) {
		this.id = id;
		this.type = "First Time Customer";
		this.disOb = disOb;
	}
}

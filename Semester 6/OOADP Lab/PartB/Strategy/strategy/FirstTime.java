package strategy;

public class FirstTime extends Customer {
	public FirstTime(String id) {
		this.id = id;
		this.type = "First Time Customer";
		this.disOb = new FTCDiscount();
	}
}

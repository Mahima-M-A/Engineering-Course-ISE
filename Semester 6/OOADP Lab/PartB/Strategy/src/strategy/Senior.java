package strategy;

public class Senior extends Customer {
	public Senior(String id) {
		this.id = id;
		this.type = "Senior Citizen Customer";
		this.disOb = new SCDiscount();
	}
}

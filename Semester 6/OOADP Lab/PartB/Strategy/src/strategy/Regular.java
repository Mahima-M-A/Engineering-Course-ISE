package strategy;

public class Regular extends Customer {
	public Regular(String id) {
		this.id = id;
		this.type = "Regular Customer";
		this.disOb = new RCDiscount();
	}
}

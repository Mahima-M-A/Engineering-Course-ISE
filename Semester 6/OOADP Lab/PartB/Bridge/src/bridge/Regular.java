package bridge;

public class Regular extends Customer {
	public Regular(String id, Discount disOb) {
		this.id = id;
		this.type = "Regular Customer";
		this.disOb = disOb;
	}
}

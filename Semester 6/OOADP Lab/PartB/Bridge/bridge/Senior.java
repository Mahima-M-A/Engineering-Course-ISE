package bridge;

public class Senior extends Customer {
	public Senior(String id, Discount disOb) {
		this.id = id;
		this.type = "Senior Citizen Customer";
		this.disOb = disOb;
	}
}

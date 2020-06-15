package observer;

public class Customer extends Observer {
	Subject store;
	String id;
	double disPercent;
	public Customer(Subject subject, String id) {
		this.id = id;
		store = subject;
		store.attach(this);
	}
	public void update(float disPercent) {
		this.disPercent = disPercent;
		System.out.println(id+" gets a discount of "+disPercent+"%");
	}
	public String toString() {
		return id;
	}
}

package factory;

public class CustomerFactory {
	public Customer getCustomer(String type) {
		if(type.equalsIgnoreCase("FTC")) {
			return new FirstTime();
		} else if(type.equalsIgnoreCase("RC")) {
			return new Regular();
		} else if(type.equalsIgnoreCase("SC")) {
			return new Senior();
		}
		return null;
	}
}

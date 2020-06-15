import factory.Customer;
import factory.CustomerFactory;

public class MainClass {
	public static void main(String[] args) {
		CustomerFactory ob = new CustomerFactory();
		Customer c = ob.getCustomer("ftc");
		c.getCustType();
		c = ob.getCustomer("sc");
		c.getCustType();
		c = ob.getCustomer("rc");
		c.getCustType();
	}
}

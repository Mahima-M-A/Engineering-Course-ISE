package template;

public abstract class OrderProcessing {

	abstract Item selectItem();
	abstract void doPayment(Item i);
	abstract void doDelivery();
	float shipCharges = 50;
	public void purchaseItem() {
		Item i=selectItem();
		if(i!=null) {			
			doPayment(i);
			doDelivery();
		}
	}
}

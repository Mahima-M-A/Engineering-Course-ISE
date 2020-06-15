package adapter;

public class GST implements TaxCalculator{
	public double calcTax(int qty, double amt) {
		return qty*amt*0.18;
	}
}

package adapter;

public class MauriTax {
	public double calcTaxAmt(int qty, double amt) {
		return qty*amt*0.10;
	}
}

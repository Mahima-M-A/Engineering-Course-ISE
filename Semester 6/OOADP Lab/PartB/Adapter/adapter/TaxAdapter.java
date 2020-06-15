package adapter;

public class TaxAdapter implements TaxCalculator {
	private MauriTax mtax;
	public TaxAdapter() {
		mtax = new MauriTax();
	}
	public double calcTax(int qty, double amt) {
		return mtax.calcTaxAmt(qty, amt);
	}
}

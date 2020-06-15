package strategy;

public class SCDiscount implements Discount {
	public double calcDis(double amt) {
		return amt*0.10;
	}
}

package strategy;

public class RCDiscount implements Discount {
	public double calcDis(double amt) {
		return 0.12*amt;
	}
}

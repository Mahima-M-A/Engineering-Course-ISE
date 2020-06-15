package strategy;

public class FTCDiscount implements Discount {
	public double calcDis(double amt) {
		return 0.15*amt;
	}
}

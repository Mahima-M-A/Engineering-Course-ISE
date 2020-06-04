import java.util.HashMap;
import java.util.Scanner;

public class NumberThread implements Runnable {
	HashMap<Integer,String> hm = new HashMap<>();

	public NumberThread() {
		hm.put(0, "Zero");
		hm.put(1, "One");
		hm.put(2, "Two");
		hm.put(3, "Three");
		hm.put(4, "Four");
		hm.put(5, "Five");
		hm.put(6, "Six");
		hm.put(7, "Seven");
		hm.put(8, "Eight");
		hm.put(9, "Nine");
	}
	@Override
	public void run() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a 4 digit number: ");
		int n = sc.nextInt();
		String res = "";
		while(n>0) {
			int r = n%10;
			res = r + "-" + hm.get(r) + "\n" +  res;
			n /= 10;
		}
		System.out.println(res);
	}
}

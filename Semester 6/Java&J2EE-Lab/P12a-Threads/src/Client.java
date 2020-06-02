public class Client {
	public static void main(String[] args) {
		NumberThread thread1 = new NumberThread();
		VowelThread thread2 = new VowelThread();
		
		Thread t1 = new Thread(thread1);
		Thread t2 = new Thread(thread2);
		t1.start();
		t2.start();
	}
}

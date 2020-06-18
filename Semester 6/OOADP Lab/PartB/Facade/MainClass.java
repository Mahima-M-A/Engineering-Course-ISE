import facade.Sports2000Facade;

public class MainClass {
	public static void main(String[] args) {
		Sports2000Facade f=new Sports2000Facade(true);
		f.displayItems();
		f.selectItems();
		f.dispAmount();
	}
}

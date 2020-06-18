package facade;

public class Sports2000Facade {
	ItemPurchased i;
	Sport2000ProcessSales s;
	
	public Sports2000Facade(boolean b) {
		i=new ItemPurchased();
		s=new Sport2000ProcessSales(b,i);
	}
	
	public void displayItems() {
		i.itemlist.displayMenu();
	}
	
	public void selectItems() {
		i.selectItems();
	}
	
	public void dispAmount() {
		s.processSales();
	}

}

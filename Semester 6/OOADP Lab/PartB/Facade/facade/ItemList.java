package facade;

import java.util.ArrayList;

public class ItemList {
	ArrayList<Item> al=new ArrayList<Item>();

	public ItemList() {
		al.add(new Item(1, "Item1", 100));
		al.add(new Item(2, "Item2", 250));
		al.add(new Item(3, "Item3", 500));
	}
	public void displayMenu() {
		System.out.println("List of Items:-");
		for(Item i:al) {
			System.out.println("\nID: "+i.id+"\nName: "+i.name+"\nPrice: "+i.price);
		}
	}
}

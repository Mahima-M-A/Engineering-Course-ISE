package facade;

import java.util.Scanner;

public class ItemPurchased {
	ItemList itemlist;
	float amt = 0;
	int noOfItems = 0;
	public ItemPurchased() {
		itemlist = new ItemList();
	}

	public void selectItems() {
		Scanner in=new Scanner(System.in);
		String ch;
		do {
			System.out.print("\nEnter of Item id: ");
			int id=Integer.parseInt(in.nextLine());
			System.out.print("Enter Quantity of Item "+id+": ");
			int qty=Integer.parseInt(in.nextLine());
			System.out.println("Do you want to purchase more items(y/n): ");
			ch=in.nextLine();
			this.amt += itemlist.al.get(id-1).price*qty;
			this.noOfItems++;
		}while(ch.equals("y"));
	}
	
	public int getNoOfItems() {
		return this.noOfItems;
	}
	
	public float getAmt() {
		return this.amt;
	}
}

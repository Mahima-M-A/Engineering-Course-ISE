package template;

import java.util.Scanner;

public class OnlineOrder extends OrderProcessing {

	ItemList menu;
	public OnlineOrder() {
		menu=new ItemList();
	}

	@Override
	Item selectItem() {
		menu.displayMenu();
		System.out.println("Enter ID of Product: ");
		Scanner in=new Scanner(System.in);
		int c=Integer.parseInt(in.nextLine());
		for(Item l:menu.al) {
			if(l.getID()==c) {
				return l;
			}	
		}
		System.out.println("Item not Found!");
		return null;
	}

	@Override
	void doPayment(Item i) {
		System.out.println("\nSelected Item:-");
		System.out.println("ID: "+i.id);
		System.out.println("Name: "+i.name);
		System.out.println("Price: "+i.price);
		System.out.println("Shipping charges: "+shipCharges);
		System.out.println("\nAmount to be paid: "+(i.price+shipCharges));
		System.out.println("\nPayment Modes:- Net-banking");
		netbank();
	}

	private void netbank() {
		System.out.println("Thanks for the Net-banking Payment!");		
	}

	@Override
	void doDelivery() {
		System.out.println("Your product will be delivered at your Address!");
	}
}

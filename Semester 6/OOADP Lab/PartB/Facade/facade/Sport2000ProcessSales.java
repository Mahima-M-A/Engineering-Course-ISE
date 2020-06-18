package facade;

import java.util.Scanner;

public class Sport2000ProcessSales {
	boolean giftCert;
	ItemPurchased item;
	public Sport2000ProcessSales(boolean g, ItemPurchased i) {
		giftCert=g;
		item=i;
	}
	
	void processSales() {
		float amount = item.getAmt();
		int noOfItems = item.getNoOfItems();
		if(!giftCert) {
			System.out.println("You don't have a Gift Certificate!");
			System.out.println("\nNo. of items bought: "+noOfItems);
			System.out.println("Amount Payable: "+ item.getAmt());
		}
		else {
			Scanner in=new Scanner(System.in);
			System.out.print("Enter Gift Certificate Value: ");
			float certValue=Float.parseFloat(in.nextLine());
			if(noOfItems<=0) {
				System.out.println("No Items in Cart!");
			}
			else if(noOfItems>1) {
				System.out.println("Only one Item can be purchased using Gift Certificate");
			}
			else if(amount>certValue) {
				System.out.println("\nNo. of items bought: "+noOfItems+"\nTotal Amount: "+amount);
				System.out.println("Please pay balance amount in Cash: Rs."+(amount-certValue));
			}
			else if(amount<=certValue) {
				System.out.println("\nNo. of items bought: "+noOfItems+"\nTotal Amount: "+amount);
				System.out.println("No cashback will be Refunded! Thankyou for your Purchase!");
			}
		}
	}
}
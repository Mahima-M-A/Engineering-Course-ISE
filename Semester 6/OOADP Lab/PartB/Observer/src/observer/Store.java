package observer;

import java.util.ArrayList;

public class Store extends Subject {
	float disPercent;
	String name;
	ArrayList<Observer>	list;
	public Store(String name) {
		this.name = name;
		list = new ArrayList<Observer>();
	}
	public void attach(Observer o) {
		list.add(o);
		System.out.println("Customer "+o+" has been added to "+name);
	}
	public void detach(Observer o) {
		try {
			list.remove(list.indexOf(o));	
			System.out.println("Customer "+o+" has been removed from "+name);
		}
		catch (NullPointerException e) {
			System.out.println("No such Customer called "+o+" in "+name);
		}
	}
	public void notifyObservers() {
		for(Observer o : list) {
			o.update(this.disPercent);
		}
	}
	public void setDisPercent(String festival, float disPercent) {
		this.disPercent = disPercent;
		System.out.println("New Discount Offer on Account of "+festival);
		notifyObservers();
	}

}

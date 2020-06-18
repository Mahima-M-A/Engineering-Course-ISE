import abstractFactory.DiffAbledSportsFactory;
import abstractFactory.IndoorRegularGames;
import abstractFactory.OutdoorAdventureSports;
import abstractFactory.OutdoorRegularGames;
import abstractFactory.RegularSportsFactory;
import abstractFactory.SportsCategoryFactory;

public class MainClass {

	public static void main(String[] args) {
		OutdoorAdventureSports sp1;
		OutdoorRegularGames sp2;
		IndoorRegularGames sp3;
		
		SportsCategoryFactory ob=new RegularSportsFactory();
		sp1=ob.getOutdoorAdventureSports("trekking");
		sp2=ob.getOutdoorRegularGames();
		sp3=ob.getIndoorRegularGames();
		
		sp1.getSportName();
		sp2.getSportName();
		sp3.getSportName();
		
		SportsCategoryFactory ob1=new DiffAbledSportsFactory();
		sp1=ob1.getOutdoorAdventureSports("Paragliding");
		sp2=ob1.getOutdoorRegularGames();
		sp3=ob1.getIndoorRegularGames();
		
		sp1.getSportName();
		sp2.getSportName();
		sp3.getSportName();
	}
}

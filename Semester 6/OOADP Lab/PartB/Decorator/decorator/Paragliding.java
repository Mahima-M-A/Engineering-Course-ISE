package decorator;
public class Paragliding extends AdventureGames {
	Sports sports;
    public Paragliding(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
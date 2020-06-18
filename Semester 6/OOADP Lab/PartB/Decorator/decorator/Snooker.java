package decorator;
public class Snooker extends GamesOnTable {
	Sports sports;
    public Snooker(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
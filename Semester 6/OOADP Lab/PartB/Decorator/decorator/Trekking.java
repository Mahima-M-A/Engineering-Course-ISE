package decorator;
public class Trekking extends AdventureGames {
	Sports sports;
    public Trekking(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
package decorator;
public class Kabaddi extends CourtGames {
	Sports sports;
    public Kabaddi(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
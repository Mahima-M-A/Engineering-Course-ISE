package decorator;
public class Badminton extends CourtGames {
	Sports sports;
    public Badminton(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
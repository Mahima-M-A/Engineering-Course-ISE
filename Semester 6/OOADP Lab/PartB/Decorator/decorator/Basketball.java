package decorator;
public class Basketball extends CourtGames {
	Sports sports;
    public Basketball(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
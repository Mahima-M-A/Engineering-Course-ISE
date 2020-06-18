package decorator;
public class Cricket extends StadiumGames {
	Sports sports;
    public Cricket(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
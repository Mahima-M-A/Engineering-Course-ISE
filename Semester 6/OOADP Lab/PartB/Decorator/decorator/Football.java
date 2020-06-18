package decorator;
public class Football extends StadiumGames {
	Sports sports;
    public Football(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
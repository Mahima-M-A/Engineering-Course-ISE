package decorator;
public class Carrom extends BoardGames {
	Sports sports;
    public Carrom(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
package decorator;
public class Chess extends BoardGames {
	Sports sports;
    public Chess(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
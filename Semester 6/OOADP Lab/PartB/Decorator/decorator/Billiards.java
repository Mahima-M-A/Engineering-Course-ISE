package decorator;
public class Billiards extends GamesOnTable {

	Sports sports;
    public Billiards(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
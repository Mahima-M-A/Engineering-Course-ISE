package decorator;
public class Baseball extends StadiumGames {
	Sports sports;
    public Baseball(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
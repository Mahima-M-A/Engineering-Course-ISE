package decorator;
public class HighJump extends Athletics {
	Sports sports;
    public HighJump(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
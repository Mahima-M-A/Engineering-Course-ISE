package decorator;
public class LongJump extends Athletics {
	Sports sports;
    public LongJump(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
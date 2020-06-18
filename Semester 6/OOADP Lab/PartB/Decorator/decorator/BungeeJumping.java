package decorator;
public class BungeeJumping extends AdventureGames {
	Sports sports;
    public BungeeJumping(Sports sports) {
    	this.sports=sports;
    }

	@Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
	}
}
package decorator;
public class TableTennis extends GamesOnTable {
	Sports sports;
    public TableTennis(Sports sports) {
    	this.sports=sports;
    }

    @Override
	public int getCurrentStock() {
		return 2+sports.getCurrentStock();
    }
}
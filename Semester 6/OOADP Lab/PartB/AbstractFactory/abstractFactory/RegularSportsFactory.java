package abstractFactory;

public class RegularSportsFactory implements SportsCategoryFactory {

	@Override
	public OutdoorAdventureSports getOutdoorAdventureSports(String name) {
		if(name.equalsIgnoreCase("Bungee Jumping"))
			return new BungeeJumpingRegular();
		else if(name.equalsIgnoreCase("Paragliding"))
			return new ParaglidingRegular();
		else if(name.equalsIgnoreCase("Trekking"))
			return new TrekkingRegular();
		else
			return null;
	}

	@Override
	public OutdoorRegularGames getOutdoorRegularGames() {
		return new CricketRegular();
	}

	@Override
	public IndoorRegularGames getIndoorRegularGames() {
		return new TableTennisRegular();
	}
}
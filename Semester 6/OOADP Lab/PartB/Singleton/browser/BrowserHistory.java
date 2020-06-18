package browser;

import java.util.ArrayList;

public class BrowserHistory {

	public static BrowserHistory instance = new BrowserHistory();
	ArrayList<String> urlList;
	private BrowserHistory() {
		urlList = new ArrayList<String>();
	}
	
	public static BrowserHistory getInstance() {
		return instance;
	}
	
	public void addUrl(String url) {
		urlList.add(url);
	}
	
	public void showUrls() {
		for(String url : urlList) {
			System.out.println(url);
		}
	}
}

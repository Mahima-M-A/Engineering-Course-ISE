import browser.BrowserHistory;

public class MainClass {
	public static void main(String[] args) {
		BrowserHistory s1 = BrowserHistory.getInstance();
		s1.addUrl("www.google.com");
		BrowserHistory s2 = BrowserHistory.getInstance();
		s2.addUrl("www.gmail.com");
		BrowserHistory s3 = BrowserHistory.getInstance();
		s3.showUrls();
	}
}

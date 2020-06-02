import java.util.ArrayList;
import java.util.Scanner;

public class VowelThread implements Runnable {
	ArrayList<Character> vowels = new ArrayList<>();
	
	public VowelThread() {
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
	}
	
	@Override
	public void run() {
		System.out.println("Enter a word: ");
		Scanner sc = new Scanner(System.in);
		String word = sc.next();
		word = word.toLowerCase();

		int c = 0;
		String v = "";
		for(int i = 0;i < word.length();i++){
			char ch = word.charAt(i);
			if(vowels.contains(ch)) {
				c++;
				if(!v.contains(String.valueOf(ch)))
					v = v + " " + ch;
			}
		}
		System.out.println("Vowels: "+v);
		System.out.println("Count: "+c);
	}
}

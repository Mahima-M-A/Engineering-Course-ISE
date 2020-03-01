import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class BookCollection {

    static String title, author, publisher;
    static double price;
    static ArrayList<Book> al = new ArrayList<Book>();
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter number of books: ");
        int n = sc.nextInt();
        for(int i=0; i<n; i++) {
            getBookDetails();
            addBookDetails();
        }

        System.out.println("**********Original Collection**********");
        for (Book b : al) {
            System.out.println(b);
        }

        ArrayList<Book> al1 = new ArrayList<Book>(al);
        Collections.sort(al1);
        System.out.println("\n***********Sorted Collection**********");
        for (Book b : al1) {
            System.out.println(b);
        }
    }

    public static void getBookDetails() {
        System.out.println("Enter book title:");
        title = sc.next();
        System.out.println("Enter book author:");
        author = sc.next();
        System.out.println("Enter book publisher:");
        publisher = sc.next();
        System.out.println("Enter book price:");
        price = sc.nextDouble();
        System.out.println();
    }

    public static void addBookDetails() {
        al.add(new Book(title, author, publisher, price));
    }
}

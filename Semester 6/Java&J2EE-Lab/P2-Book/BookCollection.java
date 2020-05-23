import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class BookCollection {

    static String title, author, publisher;
    static double price;
    static int id = 0;
    static ArrayList<Book> al = new ArrayList<Book>();
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Book> al1;

    public static void main(String[] args) {
        int flag = 1;
        while(flag == 1) {
            System.out.println("\n1. To add book details\n2. To Display the collection\n-1. To exit\nEnter choice:");
            int ch = sc.nextInt();
            switch(ch) {
                case 1:
                    getBookDetails();
                    addBookDetails();
                    break;
                case 2:
                    System.out.println("\n**********Original Collection**********");
                    for (Book b : al) {
                        System.out.println(b);
                    }
                    break;
                case -1:
                    flag = 0;
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }

        sortBooks();
        otherOperations();
    }

    public static void getBookDetails() {
        sc.nextLine();
        System.out.println("Enter book title:");
        title = sc.nextLine();
        System.out.println("Enter book author:");
        author = sc.nextLine();
        System.out.println("Enter book publisher:");
        publisher = sc.nextLine();
        System.out.println("Enter book price:");
        price = sc.nextDouble();
        System.out.println();
    }

    public static void addBookDetails() {
        al.add(new Book(id++, title, author, publisher, price));
    }

    public static void sortBooks() {
        al1 = new ArrayList<Book>(al);
        Collections.sort(al1);
        System.out.println("\n***********Sorted Collection**********");
        for (Book b : al1) {
            System.out.println(b);
        }
    }

    public static void otherOperations() {
        sc.nextLine();
        System.out.println("Enter the author name:");
        String auth = sc.nextLine();
        for (Book b : al) {
            if(b.author.equalsIgnoreCase(auth)) {
                System.out.println(b);
            }
        }

        ArrayList<Book> al2 = new ArrayList<Book>();
        System.out.println("Enter the book price:");
        double pri = sc.nextDouble();
        for (Book b : al1) {
            if(b.price > pri) {
                al2.add(b);
                System.out.println(b);
            }
        }
        for (Book b : al2) {
                System.out.println(b);
        }

        System.out.println("Enter the book title:");
        String tit = sc.nextLine();
        for (Book b : al) {
            if(b.title.contains(tit)) {
                System.out.println(b);
            }
        }

        System.out.println("Enter the publisher:");
        String p = sc.nextLine();
        for (Book b : al) {
            if(b.publisher.contains(p)) {
                System.out.println(b);
            }
        }

        System.out.println("Enter the title whose publisher has to be changed:");
        String t = sc.nextLine();
        for (Book b : al) {
            if(b.title.contains(t)) {
                System.out.println("Current publisher: " + b.publisher);
                System.out.println("Enter the new publisher:");
                String p1 = sc.nextLine();
                b.publisher = p1;
                System.out.println(b);
            }
        }
    }
}
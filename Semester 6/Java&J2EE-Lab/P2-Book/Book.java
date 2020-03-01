public class Book implements Comparable<Book> {

    String title, author, publisher;
    Double price;

    public Book(String t, String aut, String pub, Double pr) {
        title = t;
        author = aut;
        publisher = pub;
        price = pr;
    }

    Double getPrice() {
        return price;
    }

    public String toString() {
        return "Book Details :\n  Title: " + title + "\n  Author: " + author + "\n  Publisher: " + publisher + "\n  Price: " + price;
    }

    public int compareTo(Book o) {
        return getPrice().compareTo(o.getPrice());
    }
}

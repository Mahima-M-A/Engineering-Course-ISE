public class Book implements Comparable<Book> {

    String title, author, publisher;
    Double price;
    int id;

    public Book(int id, String title, String author, String publisher, Double price) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.price = price;
    }

    Double getPrice() {
        return price;
    }

    public String toString() {
        return "Book Details :\n  ID: "+ id +"\n  Title: " + title + "\n  Author: " + author + "\n  Publisher: " + publisher + "\n  Price: " + price;
    }

    public int compareTo(Book o) {
        return getPrice().compareTo(o.getPrice());
    }
}
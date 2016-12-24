package finalProject;

public class Book implements Comparable<Book> {

    private int id;
    private int weight;

    public Book(int weight, int id) {
        this.id = id;
        this.weight = weight;
    }

    public int getWeight() {
        return this.weight;
    }

    public int getID() {
        return this.id;
    }

    @Override
    public int compareTo(Book other) {
        return Integer.compare(this.getWeight(), other.getWeight());
    }

    @Override
    public String toString() {
        return "ID: " + this.id + " WEIGHT: " + this.weight;
    }

}

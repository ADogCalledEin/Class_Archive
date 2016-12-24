package finalProject;

import java.util.ArrayList;

public class Box {

    private ArrayList<Book> contents;
    private int spaceLeft;
    private int totalBooks;

    public Box(int given_max_weight) {
        spaceLeft = given_max_weight;
        contents = new ArrayList<Book>();
        totalBooks = 0;
    }

    public void add(Book data) {
        contents.add(data);
        spaceLeft = spaceLeft - data.getWeight();
        totalBooks++;
    }

    public boolean canPut(int next_weight) {
        if (spaceLeft >= next_weight) {
            return true;
        } else {
            return false;
        }
    }

    public ArrayList<Book> getContents() {
        ArrayList<Book> data = new ArrayList<Book>();
        for (int i = 0; i < this.contents.size(); i++) {
            data.add(this.contents.get(i));

        }
        return data;
    }

    public int getIDofBook(int index) {
        return this.contents.get(index).getID();
    }

    public int getTotalBooks() {
        return this.totalBooks;
    }

}

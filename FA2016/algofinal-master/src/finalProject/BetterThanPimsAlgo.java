package finalProject;

import java.io.*;
import java.util.*;

public class BetterThanPimsAlgo {

    public static ArrayList<Box> method(ArrayList<Book> a, int max_weight, ArrayList<Box> out) {
        Box currentBox = new Box(max_weight);
        Collections.sort(a);                //Collections.sort uses quicksort (linearithmic time)
        Collections.reverse(a);
        int smallestBookIndex = a.size() - 1;
        while (!a.isEmpty()) {
            if (currentBox.canPut(a.get(0).getWeight())) {
                currentBox.add(a.get(0));
                a.remove(0);
                smallestBookIndex--;
            } else if (currentBox.canPut(a.get(smallestBookIndex).getWeight())) {
                currentBox.add(a.get(smallestBookIndex));
                a.remove(smallestBookIndex);
                smallestBookIndex--;
            } else {
                out.add(currentBox);
                currentBox = new Box(max_weight);
            }
        }
        out.add(currentBox);
        return out;

    }


    public static void main(String[] args) throws IOException {
        //Constructing a Scanner with the data given, as well as assigning where to put the output,
        //then converting the scanner into an arraylist
        File inFile = null;
        String outFile = null;
        if (0 < args.length) {
            inFile = new File(args[0]);
            outFile = args[1];
        } else {
            System.err.println("Invalid arguments count:" + args.length);
            System.exit(1);
        }

        BufferedReader buffer = new BufferedReader(new FileReader(inFile));
        Scanner input = new Scanner(buffer);

        int numberOfBooks = input.nextInt();   //As much as I want to take this out, I'm leaving it because taking it out breaks everything
        int maxWeight = input.nextInt();
        ArrayList<Integer> ini = new ArrayList<Integer>();
        while (input.hasNext()) {
            ini.add(input.nextInt());
        }
        input.close();
        buffer.close();

        ArrayList<Book> in = new ArrayList<Book>();
        Iterator iniIt = ini.iterator();
        int i = 0;

        while (iniIt.hasNext()) {
            in.add(new Book((int) iniIt.next(), i));
            i++;
        }

        ArrayList<Box> out = new ArrayList<>();
        method(in, maxWeight, out);

        ArrayList<Integer> output = new ArrayList<>();
        output.add(out.size());
        for (int j = 0; j < out.size(); j++) {
            output.add(out.get(j).getTotalBooks());
            for (int k = 0; k < out.get(j).getTotalBooks(); k++) {
                output.add(out.get(j).getIDofBook(k));
            }
        }

        for (int j = 0; j < output.size(); j++) {
            System.out.println(output.getClass());
            try (PrintWriter outNow = new PrintWriter(new BufferedWriter(new FileWriter(outFile, true)))) {
                outNow.println(output.get(j));
            } catch (IOException e) {
                System.out.println(e);
            }
        }


    }

}


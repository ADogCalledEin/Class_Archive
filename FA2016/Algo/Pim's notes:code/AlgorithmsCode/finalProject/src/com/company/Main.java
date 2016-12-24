package com.company;

import java.io.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        if (args.length != 2){
            System.err.println("Invalid command line, exactly 2 arguments required");
            System.exit(1);
        }
        FileInputStream fstream = new FileInputStream(args[0]);

    }
}

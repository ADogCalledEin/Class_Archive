package scheme_calculator;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

/**
 * Created by ein on 12/2/16.
 */
public class scheme_calc {



    public static void calculate(mystack nums, mystack opers, String[][] symbolTable, int tableCount){
        String op = (String)opers.pop();
        double v = Double.parseDouble((String)nums.pop());
        switch (op) {
            case "+":
                v = Double.parseDouble((String)nums.pop()) + v;
                break;
            case "-":
                v = Double.parseDouble((String)nums.pop()) - v;
                break;
            case "*":
                v = Double.parseDouble((String)nums.pop()) * v;
                break;
            case "/":
                v = Double.parseDouble((String)nums.pop()) / v;
                break;
            case "sqrt":
                v = Math.sqrt(v);
                break;
            case "sin":
                v = Math.sin(v);
                break;
            case "cos":
                v = Math.cos(v);
                break;
            case "square":
                v = v * v;
            case "define":
                String assignment = (String) nums.peek(nums.getTop());
                String number = (String) nums.peek(nums.getTop() - 1);
                symbolTable[0][tableCount] = assignment;
                symbolTable[1][tableCount] = number;
                break;
        }
        nums.push(String.valueOf(v));
    }



    public static void main(String[] args) throws FileNotFoundException {
        mystack<String> opers = new mystack<String>();
        mystack<String> nums = new mystack<String>();

        int calc = 0;
        int tableCount = -1;
        String[][] symbolTable = new String[2][100];


        String inFile = args[0];
        BufferedReader buffer = new BufferedReader(new FileReader(inFile));

        Scanner input = new Scanner(buffer);

        while(input.hasNext()) {
            String s = input.next();
//            System.out.println(s);

            if (s.charAt(0) == '('){
                s = s.substring(1);
            }else if (s.charAt(0) == ')'){
                calculate(nums, opers, symbolTable, tableCount);
                s = null;
            }else if (s.charAt(s.length()-1) == ')') {
                int closing = 0;
                while (s.charAt(s.length() - 1) == ')') {
                    s = s.substring(0, s.length() - 1);
                    closing++;
                    calc = 1;
                }
                nums.push(s);
                while (closing != 0) {
                    calculate(nums, opers, symbolTable, tableCount);
                    closing--;
                }
                s = null;
            }

            if (s == null){
                continue;
            }
            else if (s.equals("+")) opers.push(s);
            else if (s.equals("-")) opers.push(s);
            else if (s.equals("*")) opers.push(s);
            else if (s.equals("/")) opers.push(s);
            else if (s.equals("sqrt")) opers.push(s);
            else if (s.equals("sin")) opers.push(s);
            else if (s.equals("cos")) opers.push(s);
            else if (s.equals("square")) opers.push(s);
            else if (s.equals("define")){
                opers.push(s);
                tableCount++;
            } else {
                nums.push(s);
            }
        }
        //nums.pop();
        nums.pstack();

    }

}

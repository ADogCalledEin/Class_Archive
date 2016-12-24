package rpn_calculator;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

/**
 * Created by ein on 11/27/16.
 */
public class rpn_calc {
    public static double[] stack = new double[100];
    public static int top = -1;
    public static int max_size = 100;


    //BASIC STACK OPERATIONS
    public static boolean isEmpty(){
        if (top == -1){
            return true;
        }else {
            return false;
        }
    }

    public static boolean isFull(){
        if (top == (max_size-1)){
            return true;
        }else{
            return false;
        }
    }

    public static double peek(int i){
        if ( i > top){
            System.out.println("Tried to peek above stack.");
            System.exit(1);
        }
        return stack[i];

    }

    public static double pop(){
        double data = 0;
        if(!isEmpty()){
            data = stack[top];
            top--;
        }else{
            System.out.println("Stack is empty. Nothing to pop.\n");
            System.exit(1);
        }

        return data;
    }

    public static void push(double data){
        if(!isFull()){
            stack[top + 1] = data;
            top++;
        }else{
            System.out.println("Stack is full. Cannot push.\n");
            System.exit(1);
        }
    }

    public static void pstack(){
        for (int i = top; i > -1; i--){
            System.out.println(stack[i]);
        }
    }

    //MATH
    public static void add(){
        double b = pop();
        double a = pop();
        push(a + b);
    }

    public static void sub(){
        double b = pop();
        double a = pop();
        push(a - b);
    }

    public static void mul(){
        double b = pop();
        double a = pop();
        push(a * b);
    }

    public static void div(){
        double b = pop();
        double a = pop();
        push(a / b);
    }

    public static void idiv(){
        double b = pop();
        double a = pop();
        push(Math.floor(a / b));
    }

    public static void mod(){
        double b = pop();
        double a = pop();
        push(a % b);
    }

    public static void sqrt(){
        double a = pop();
        push(Math.sqrt(a));
    }

    public static void sin(){
        double a = pop();
        push(Math.sin(a));
    }

    public static void cos(){
        double a = pop();
        push(Math.cos(a));
    }

    //NOW ON TO STACK MANIPULATION
    public static void dup(){
        double a = pop();
        double data = a;
        push(a);
        push(data);
    }

    public static void exch(){
        double a = pop();
        double b = pop();
        push(a);
        push(b);
    }

    public static void index(){
        double in = pop();
        int index = (int)in;
        int out = top - index;
        double data = stack[out];
        push(data);
    }

    public static void copy(){
        double depthd = pop();
        int depthi = (int)depthd;
        int depth = top - depthi + 1;
        int snap_top = top;

        for (int i = depth; i < snap_top + 1; i++) push(stack[i]);
    }

    public static void roll() {
        double depth = pop();
        double dist = pop();

        int depthi = (int)depth;
        int disti = (int)dist;

        if (depthi > 0){
            double ar[] = new double[disti];
            int count = 0;
            for (int i = top - depthi + 1; i <= top; i++){
                ar[count] = stack[i];
                count++;
            }

            for (int i = top - disti + 1; i < top - depthi + 1; i++){
                ar[count] = stack[i];
                count++;
            }

            for(int i = 0; i < disti; i++){
                pop();
            }

            for(int i = 0; i < ar.length ; i++){
                push(ar[i]);
            }
        }else if(depthi < 0){
            double ar[] = new double[disti];
            depthi = Math.abs(depthi);
            depthi = (disti - depthi);
            int count = 0;

            for (int i = top - depthi + 1; i <= top; i++){
                ar[count] = stack[i];
                count++;
            }

            for (int i = top - disti + 1; i < top - depthi + 1; i++){
                ar[count] = stack[i];
                count++;
            }

            for(int i = 0; i < disti; i++){
                pop();
            }

            for(int i = 0; i < ar.length ; i++){
                push(ar[i]);
            }
        }else{
            return;
        }





    }


    public static void main(String[] args) throws FileNotFoundException {
//        push(0);
//        push(1);
//        push(2);
//        push(3);
//        push(4);
//        push(5);
//        push(6);
//        push(7);
//        push(8);
//        push(6);
//        push(-2);
//        pstack();
//        roll();
//        System.out.println();
//        pstack();
        String input = args[0];
        BufferedReader buffered = new BufferedReader(new FileReader(input));
        Scanner inFile = new Scanner(buffered);

        while(inFile.hasNext()){

            if(inFile.hasNextInt()) {
                String next = inFile.next();
                double nextd = Double.parseDouble(next);
                push(nextd);
            }else if(inFile.hasNextDouble()) {
                String next = inFile.next();
                double nextd = Double.parseDouble(next);
                push(nextd);
            }else{
                String op = inFile.next();

                switch(op){
                    case "add": add();
                        break;
                    case "sub": sub();
                        break;
                    case "mul": mul();
                        break;
                    case "div": div();
                        break;
                    case "idiv": idiv();
                        break;
                    case "mod": mod();
                        break;
                    case "sqrt": sqrt();
                        break;
                    case "sin": sin();
                        break;
                    case "cos": cos();
                        break;
                    case "pstack": pstack();
                        break;
                    case "dup": dup();
                        break;
                    case "exch": exch();
                        break;
                    case "pop": pop();
                        break;
                    case "index": index();
                        break;
                    case "copy": copy();
                        break;
                    case "roll": roll();
                        break;
                }
            }

        }
    }
}

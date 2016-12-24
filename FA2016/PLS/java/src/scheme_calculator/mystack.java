package scheme_calculator;

import java.util.ArrayList;

/**
 * Created by ein on 12/2/16.
 */
public class mystack<E> {

    private ArrayList<E> contents;
    private int top;

    public mystack(){
        this.contents = new ArrayList<>();
        this.top = -1;
    }

    public boolean isEmpty(){
        return (this.top == -1);
    }


    public int push(E data){
        this.contents.add(data);
        this.top++;
        return 1;
    }

    public Object pop(){
        Object data = new Object();
        data = this.contents.get(this.top);
        this.contents.remove(this.top);
        this.top--;

        return data;
    }

    public Object peek(int index){
        Object data = new Object();
        if(this.isEmpty()) {
            System.out.println("Stack empty. Nothing to print.");
            System.exit(1);
        }else{
            data = this.contents.get(index);
        }
        return data;
    }

    public void pstack(){
        if(this.isEmpty()){
            System.out.println("Stack empty. Nothing to print.");
            System.exit(1);
        }else {
            for (int i = this.contents.size(); i > 0; --i) {
                System.out.println(this.contents.get(i - 1));
            }
        }
    }

    public int getTop(){
        return this.top;
    }



}

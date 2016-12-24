package homework7;

import static org.junit.Assert.*;


/**
 * Created by daberoni on 10/31/16.
 */

public class Homework7Test {

    @org.junit.Test
    public void isMinimumBinaryHeap() throws Exception {
        Integer[] test1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // true
        Integer[] test2 = {0, 1, 2, 3, 4, 5, 6}; // true
        Integer[] test3 = {0, 1, 2, 3, 4, 5, 6, 7}; // true
        Integer[] test4 = {0, 1, 2, 3, 4, 5, 6, 7, 8}; // true
        Integer[] test5 = {10, 9, 8, 7}; // false
        Integer[] test6 = {1, 5, 7, 6, 10, 15, 17, 12}; // true
        String[] test7 = {"A", "T", "S", "R", "P", "N", "O", "A", "E", "I", "H", "G"};// false
        Integer[] test8 = {1, 5, 7, 6, 10, 15, 17}; //true
        Integer[] test9 = {1, 5, 7, 6, 10, 15, 17, 12, 11}; //true
        Integer[] test10 = {1, 5, 7, 6, 10, 15, 17, 12, 16}; //true
        Integer[] test11 = {1, 21, 7, 6, 10, 15, 17, 12, 16}; //false
        Integer[] test12 = {1, 5, 7, 6, 10, 15, 17, 12, 16, 18}; //true
        Integer[] test13 = {1, 20, 7, 6, 10, 15, 17, 12, 16, 18}; //false
        Integer[] test14 = {1, 5, 7, 6, 20, 15, 17, 12, 16, 18}; //false
        Integer[] test15 = {1, 5, 7, 6, 10, 15, 17, 12, 16, 18, 13}; //true
        Integer[] test16 = {1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //false
        String[] test18 = {"A", "X", "Z", "R", "Y", "B", "B", "B", "H", "Z", "H", "D"};// false
        String[] test19 = {"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A"};// should be true
        Integer[] test20 = {0, 0, 0, 0, 0, 0, 0}; //should be true


        assertEquals(true, Homework7.isMinimumBinaryHeap(test1));
        System.out.println("test1");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test2));
        System.out.println("test2");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test3));
        System.out.println("test3");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test4));
        System.out.println("test4");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test5));
        System.out.println("test5");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test6));
        System.out.println("test6");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test7));
        System.out.println("test7");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test8));
        System.out.println("test8");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test9));
        System.out.println("test9");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test10));
        System.out.println("test10");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test11));
        System.out.println("test11");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test12));
        System.out.println("test12");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test13));
        System.out.println("test13");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test14));
        System.out.println("test14");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test15));
        System.out.println("test15");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test16));
        System.out.println("test16");
        assertEquals(false, Homework7.isMinimumBinaryHeap(test18));
        System.out.println("test18");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test19));
        System.out.println("test19");
        assertEquals(true, Homework7.isMinimumBinaryHeap(test20));
        System.out.println("test20");
    }
}
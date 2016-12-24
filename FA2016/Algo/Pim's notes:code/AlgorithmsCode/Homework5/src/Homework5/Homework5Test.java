package Homework5;

import static org.junit.Assert.*;

/**
 * Created by Pim on 10/2/16.
 */
public class Homework5Test {

    @org.junit.Test
    public void testOrderedMatrixContains() throws Exception {
        int[][] test1 = new int[][]{
                {  1,  4,  7},
                { 12, 17, 28},
                { 15, 26, 39}
        };
        int[][] test2 = new int[][]{
                        {1, 2, 3, 10,18},
                        {4, 5, 6, 13,21},
                        {7, 8, 9, 15,23},
                        {11,12,16,17,26},
                        {15,19,22,24,30}
        };
    boolean result;
        result = Homework5.orderedMatrixContains(test1, 17);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 15);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 7);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1,4);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 12);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 17);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 28);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 26);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test1, 39);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 30);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 24);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 22);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 19);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 15);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 9);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 23);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 4);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 3);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 18);
        assertEquals(result, true);
        result = Homework5.orderedMatrixContains(test2, 21);
        assertEquals(result, true);

    }

}
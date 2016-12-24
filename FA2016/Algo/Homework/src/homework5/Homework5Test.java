package homework5; /**
 * Created by daberoni on 10/2/16.
 */

import static org.junit.Assert.*;

public class Homework5Test {


    @org.junit.Test
    public void containsTest() throws Exception{
        boolean result;

        int array[][] = {{0,1,2},{3,4,5},{6,7,8}};
        assertTrue(Homework5.OrderedMatrixContains(array, 5));
//
        int array1[][] = {{0,1,2,3},
                          {4,5,6,7},
                          {8,9,10,11},
                          {12,13,14,15}};
        assertTrue(Homework5.OrderedMatrixContains(array1, 9));
//
        int array2[][] = {{0,1,2},{3,4,5},{6,7,8}};
        assertFalse(Homework5.OrderedMatrixContains(array2, 9));

        int array3[][] = {{0,2,4,6},
                          {8,10,12,14},
                          {16,18,20,22},
                          {24,26,28,30}};
        assertFalse(Homework5.OrderedMatrixContains(array3,9));

        int array4[][] = {{9,10,11,12},
                          {13,14,15,16},
                          {17,18,19,20},
                          {21,22,23,24}};
        assertFalse(Homework5.OrderedMatrixContains(array4,7));

        int array5[][] = {{ 1, 4, 7},
                          { 12, 17, 28},
                          { 15, 26, 39}};
        assertTrue(Homework5.OrderedMatrixContains(array5,26));

        int array6[][] = {{ 1, 4, 7},
                          { 12, 17, 28},
                          { 15, 26, 39}};
        assertFalse(Homework5.OrderedMatrixContains(array6,27));
    }


}

import static org.junit.Assert.*;

/**
 * Created by Pim on 9/18/16.
 */
public class Homework3Test {
    @org.junit.Test
    public void sort() throws Exception {
        int[] testArray1 = new int[]{6,5,4,3,2,1};
        int[] testArray2 = new int[]{1,5,6,3,4,5,6,8,2,3,};
        int[] sortedTestArray1 = new int[]{1,2,3,4,5,6};
        Homework3.sort(testArray1, testArray1.length);
        for(int i = 0; i < testArray1.length; i++){
            System.out.println(testArray1[i]);
        }
        System.out.println(testArray1);
        assertArrayEquals(testArray1,sortedTestArray1);


    }

}
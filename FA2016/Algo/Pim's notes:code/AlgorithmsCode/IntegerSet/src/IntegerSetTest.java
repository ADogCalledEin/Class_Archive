import org.junit.Assert;
import org.junit.Test;

public class IntegerSetTest {

    @Test
    public void removeDuplicatesTest() throws Exception {
        int[] myIntArray = {1,2,3,3,4,5,6,7,7};
        int[] myIntArrayScramble = {6,7,7,8,5,4,3,2,4,5,3,2,1,3,4};
        int[] myIntArrayWithoutDups = {1,2,3,4,5,6,7};
        int[] b = IntegerSet.removeDups(myIntArray);
        int[] test = {1,2,3,4,5,6,7,8};

        Assert.assertArrayEquals(myIntArrayWithoutDups,b);

        int[] c = IntegerSet.removeDups(myIntArrayScramble);

        Assert.assertArrayEquals(test,c);

    }
    @Test
    public void equalsTest() throws Exception {
        int[] myIntArray1 = {1,2,3,4,5,6,7,8,9};
        int[] myIntArray2 = {1,2,3,3,4,5,6,7,7};
        int[] myIntArray = {1,2,3,3,4,5,6,7,7};
        IntegerSet poop = new IntegerSet(myIntArray);
        IntegerSet poop1 = new IntegerSet(myIntArray2);
        boolean result = poop.equals(poop1);
        Assert.assertEquals(result, true);
        IntegerSet poop2= new IntegerSet(myIntArray1);
        result = poop.equals(poop2);
        Assert.assertEquals(result, false);
    }

    @Test
    public void equalsObjectTest() throws Exception {

    }


}
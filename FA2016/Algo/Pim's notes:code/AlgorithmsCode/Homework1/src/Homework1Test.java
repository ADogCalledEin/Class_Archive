import static org.junit.Assert.*;

/**
 * Created by Pim on 9/5/16.
 */
public class Homework1Test {
    @org.junit.Test
    public void isCircularPermutation() throws Exception {
        String string1 = "abcd";
        String string2 = "abcd";
        String string3 = "aab";
        String string4 = "aba";
        Boolean value = false;
        value = Homework1.isCircularPermutation(string3, string4);
        assertEquals(value, TRUE);
        value = Homework1.isCircularPermutation(string1, string2);
        assertEquals(value, Boolean.TRUE);
        string2 = "abde";
        value = Homework1.isCircularPermutation(string1, string2);
        assertEquals(value, Boolean.FALSE);
        string2 = "cdab";
        value = Homework1.isCircularPermutation(string1, string2);
        assertEquals(value, Boolean.TRUE);
        string2 = "abcde";
        value = Homework1.isCircularPermutation(string1, string2);
        assertEquals(value, Boolean.FALSE);
        /*String string3 = null;
        string2 = "";
        value = Homework1.isCircularPermutation(string3, string2); */
    }

}
import static org.junit.Assert.*;


/**
 * Created by Pim on 9/21/16.
 */
public class Homework4Test {

    @org.junit.Test
    public void stackCheckerTest() throws Exception {
        boolean result;
        boolean[] test1 = new boolean[]{false,false,true,true};
        result = Homework4.StackChecker(test1);
        assertEquals(result, true);
        boolean[] test2 = new boolean[]{true,false,true,false};
        result = Homework4.StackChecker(test2);
        assertEquals(result, false);
        boolean[] test3 = new boolean[]{false,false,false,true,true,true};
        result = Homework4.StackChecker(test3);
        assertEquals(result, true);
        boolean[] test4 = new boolean[]{false,false,true,true};
        result = Homework4.StackChecker(test4);
        assertEquals(result, true);
        boolean[] test5 = new boolean[]{false,true,false,true,true,true};
        result = Homework4.StackChecker(test5);
        assertEquals(result, false);
        boolean[] test6 = new boolean[]{false,false,true,true,true};
        result = Homework4.StackChecker(test6);
        assertEquals(result, false);
        boolean[] lastcheck = new boolean[]{false,false,false,true,true,false};
        result = Homework4.StackChecker(lastcheck);
        assertEquals(result, false);
    }

}
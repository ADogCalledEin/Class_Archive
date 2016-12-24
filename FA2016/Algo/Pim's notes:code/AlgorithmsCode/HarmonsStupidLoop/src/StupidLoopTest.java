
import org.testng.annotations.Test;

import static org.junit.Assert.*;

/**
 * Created by Pim on 10/3/16.
 */
public class StupidLoopTest {
    @Test
    public void stupidLoop() throws Exception {
        int test1 = 9;
        int test2 = 10;

        int result = StupidLoop.stupidLoop(test1);
        System.out.println(result);
    }

}
import java.util.Stack;

public class Homework4 {

	/***
	 * determines if an input array is of the format where the first n values
	 *  are false and the second n values are true for all n >= 0
	 * @param b array of booleans
	 * @return true if the Boolean array contains n false values followed by
	 *    n true values for all n >= 0
	 */
	public static boolean StackChecker(boolean [] b) {
		Stack firststack = new Stack();
		Stack secondstack = new Stack();
		int falseCount = 0;
		int trueCount = 0;

		if(b == null){
			return false;
		}

		if(b[0] == true){
			return false;
		}
		if(b.length % 2 != 0){
			return false;
		}
		// push the first N elems onto the stack
		for(int i = 0; i < b.length/2; i++){
			firststack.push(b[i]);
		}
		// push the second N elems onto the stack
		for(int i = b.length/2; i < b.length; i++ ){
			secondstack.push(b[i]);
		}
		// does the mathz stuff
		for(int i = 0; i < firststack.size(); i++){
			if(firststack.elementAt(i).equals(true)){
				return false;
			}
			if(firststack.elementAt(i).equals(false)){
				falseCount++;
			}
		}
		// does more mathz stuff
		for(int i = 0; i < secondstack.size(); i++){
			if(secondstack.elementAt(i).equals(false)){
				return false;
			}
			if(secondstack.elementAt(i).equals(true)){
				trueCount++;
			}
			System.out.println(falseCount);
			System.out.println(trueCount);
		}
		// the final condition that returns true
		if(trueCount == falseCount){
			return true;
		}
		// the generic case
		return false;
	}

}
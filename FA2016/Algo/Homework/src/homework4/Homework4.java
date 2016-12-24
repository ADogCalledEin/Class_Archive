package homework4;//NAME: Griffin Siadak

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
		Stack firstHalfStack = new Stack();
		Stack secHalfStack = new Stack();
		int tcount = 0;
		int fcount = 0;

//		Checking if there are some catches we can return on
//		Like if the first value is true, we can skip everything and just end it
		if (b[0] == true){
			return false;
		}
//		Or if the array is of uneven length, which would also return false
		if ((b.length % 2) != 0 ){
			return false;
		}

//		Splitting the array into two stacks (easier to analyze that way)
		for(int i = 0; i < b.length / 2; i++){
			firstHalfStack.push(b[i]);
		}
		for(int i = (b.length / 2); i < b.length; i++ ){
			secHalfStack.push(b[i]);
		}

//		Checking the stacks, on failure returns false, else bump up the count for each result (probably overkill but worth it IMO)
		for(int i = 0; i < firstHalfStack.size(); i++){
			if (!firstHalfStack.pop().equals(false)){
				return false;
			}
			fcount++;
		}
		for(int i = 0; i < secHalfStack.size(); i++){
			if (!secHalfStack.pop().equals(true)){
				return false;
			}
			tcount++;
		}

//		Compare the counts to make sure
		if (tcount == fcount){
			return true;
		}

		return false;
		
	}
	
}

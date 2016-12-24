package Homework7;

public class Homework7 {

	/***
	 * 
	 * determines if an array represents a minimum-oriented binary heap
	 * 
	 * @param a array to check
	 * @return true if the array satisfies the conditions of being a
	 *    minimum-oriented binary heap array, otherwise false
	 */
	public static boolean isMinimumBinaryHeap(Comparable [] a) {
		for(int i = a.length-1; i != 0; i--){ // moves down one position in the array everytime
            for(int j = i; j != 0; j= j/2) { // divides the element by two and checks if they are less than
                if (a[j/2].compareTo(a[j]) > 0) {
                    return false;
                }
            }
		}
		return true;
	}	
}

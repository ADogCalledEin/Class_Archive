package homework7;


//NAME: Griffin Siadak

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
		for (int i = a.length - 1; i != 0; i--){
			int parent = i / 2;
			for (int j = i; j > parent; j /= 2){
				int result = a[parent].compareTo(a[j]);
				if (result > 0){
					return false;
				}
			}
		}
		return true;
	}

}

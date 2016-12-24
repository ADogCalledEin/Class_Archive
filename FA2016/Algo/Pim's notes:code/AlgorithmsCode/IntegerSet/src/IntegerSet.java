// you may not use any other import statements for this .class!
import java.util.Arrays;
import java.lang.IllegalArgumentException;

public class IntegerSet {
	
	private final int[] a;
	
	/***
	 * 
	 * @param input array of integers
	 * @throws IllegalArgumentException if keys is null
	 */
	public IntegerSet(int[] keys)
	{			
		// create and sort defensive copy
		a = new int[keys.length];
	    for (int i = 0; i < keys.length; i++)					
	        a[i] = keys[i]; 					
	    Arrays.sort(a);			
	}
			
	/***
	 * 
	 * @return the number of elements in the IntegerSet
	 */
	public int size() { 
		return a.length; 
	}
	  
	/***
	 * determines if an integer is a member of the IntegerSet or not.
	 * 
	 * @param key the integer to check
	 * @return true if the integer is a member of the IntegerSet, otherwise false
	 */
	public boolean contains(int key) {  
		return _binary_search(key) != -1;  
	}
						
	 
	/***
	* peforms a binary search on a sorted array of integers
	*  
	* @param key integer to search for
	* @return position in the array where an instance of the integer occurs, -1 if the key is not present
	*/
	private int _binary_search(int key) {
	  					
	     int lo  = 0;
	     int hi = a.length - 1;
	     while (lo <= hi)
	      { // Key is in a[lo..hi] or not present.				
	         int mid = lo + (hi - lo) / 2;
	         if      (key < a[mid]) hi = mid - 1;
	         else if (key > a[mid]) lo = mid + 1;
	         else return mid;				
	
	      }					
	
	     return -1; 
	  }

    public static int[] removeDups(int[] dups) {

        int length = dups.length;

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (dups[i] == dups[j]) {
                    int shiftLeft = j;
                    for (int k = j+1; k < length; k++, shiftLeft++) {
                        dups[shiftLeft] = dups[k];
                    }
                    length--;
                    j--;
                }
            }
        }

        int[] newArr = new int[length];
        for(int i = 0; i < length; i++){
            newArr[i] = dups[i];
        }
        Arrays.sort(newArr);
        return newArr;
    }

    @Override
    public boolean equals(Object obj){

        if(obj == null){
            return false;
        }
        if(!(obj instanceof IntegerSet)){
            return false;
        }
        if(obj == this){
            return true;
        }
        IntegerSet that = (IntegerSet) obj;
        if(this.size() != that.size()){
            return false;
        }
        else {
            if (this.size() != that.size()){
                return false;
            }
            else {
                for (int i = 0; i < this.size(); i++) {
                    if (this.a[i] != that.a[i]) {
                        return false;
                    }
                }
            }
        }
    return true;
    }
}

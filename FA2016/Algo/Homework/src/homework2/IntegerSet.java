package homework2;// you may not use any other import statements for this .class!
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

		int[] b = new int[keys.length];
	    for (int i = 0; i < keys.length; i++) {
			b[i] = keys[i];
		}

		Arrays.sort(b);

		// count the duplicates
		int dupeCount = 0;
		for(int i=0; i< b.length-1; i++){
			if (b[i] == b[i+1]){
				dupeCount++;
			}
		}

		// create array without dupes
		int newArr[] = new int[b.length - dupeCount];
		int y = 0;
		int t = 0;
		while(t != b.length-1){
			if (b[t] == b[t+1]){
				t++;
			}
			else {
				newArr[y] = b[t];
				y++;
				t++;
			}
		}

		//get the last value into the new array (cuz it gets missed
		newArr[y] = b[t];

		a = Arrays.copyOf(newArr, newArr.length);
	    Arrays.sort(a);

	}
			
	/***
	 * 
	 * @return the number of elements in the homework2.IntegerSet
	 */
	public int size() { 
		return a.length; 
	}
	  
	/***
	 * determines if an integer is a member of the homework2.IntegerSet or not.
	 * 
	 * @param key the integer to check
	 * @return true if the integer is a member of the homework2.IntegerSet, otherwise false
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

	  @Override
	  public boolean equals(Object obj) {
		  if (obj == this) { return true; }
		  if (obj == null) { return false; }
		  if (obj instanceof IntegerSet) {
		  		IntegerSet that = (IntegerSet)obj;
			  	if (this.size() != that.size()) { return false; }
			  	else {
			  		for (int i=0; i < this.size(); i++){
			  			if (this.a[i] != that.a[i]){
			  				return false;
						}
					}
					return true;
				}
		  }

		return false;
	  }


	public static void main(String[] args) {
		IntegerSet data = new IntegerSet(new int[] {8,8,6,6,5,4,3,2,1,1});
		IntegerSet data2 = new IntegerSet(new int[] {1,2,2,3,4,5,6,6,8});
		for(int i=0; i<data.size(); i++){
			System.out.println(data.a[i]);
		}
		System.out.println(" ");
		for(int i=0; i<data2.size(); i++){
			System.out.println(data2.a[i]);
		}
		System.out.print(data.equals(data2));
	}
}

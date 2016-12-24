package notes;

import java.util.Arrays;

public class IntegerSet {
	
	private final int[] a;
	
	public IntegerSet(int[] keys)
	{			
		a = new int[keys.length];
	    for (int i = 0; i < keys.length; i++)					
	        a[i] = keys[i]; 					// perform defensive copy
	    Arrays.sort(a);			
	}

        public int size() { return a.length; }
							
	  public boolean contains(int key)
	   {  return binary_search(key) != -1;  }
						
	  private int binary_search(int key)
	  {					
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
	  						
}

package homework1;

public class Homework1 {

	/***
	 * evaluates if two strings are circular permutations of each other
	 * 
	 *  examples: 
	 *  	s1="abcd", s2="cdab" returns true.
	 *  	s1="abcd", s2="cdba" returns false.
	 *  	s1="abcd", s2="bcd" returns false
	 *  
	 * @param s1 first string to evaluate
	 * @param s2 second string to evaluate
	 * @return true if s1 and s2 are circular permutations of each other, otherwise false
	 * @throws NullPointerException if s1 or s2 is null
	 */
	public static boolean isCircularPermutation(String s1, String s2) {
		int start = 0;
		int counter = 0;
		if (s1.length() != s2.length()){ //check if they are different lengths
			return false;
		}
		if (s1.equals(s2)){ // check if they are the same string
			return true;
		}
		else{
			for (int i = 0; i < s1.length(); i++){
				if ( s2.charAt(i) == s1.charAt(0)){
					start = i; //finding the starting character to key off of
					break;
				}
			}
			for (int i = 0; i < s1.length(); i++){
				if (s1.charAt(i) == s2.charAt((start+i) % s2.length()) ){ //"building" the comparator string
					counter++;
				}
			}
			if (counter == s1.length()){
				return true; //seeing if the string that is the "same" is the same length as the original string, which returns true
			}
		}
		return false; //if all else fails return false
		
	}

	public static void main(String[] args){
		boolean status = isCircularPermutation("abcd", "cdab"); //testing
		System.out.print(status);
	}
}

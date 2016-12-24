
public class Homework1 {

/***
 * evaluates if two strings are circular permutations of each other
 *
 *  examples:
 *   s1="abcd", s2="cdab" returns true.
 *   s1="abcd", s2="cdba" returns false.
 *   s1="abcd", s2="bcd" returns false
 *
 * @param s1 first string to evaluate
 * @param s2 second string to evaluate
 * @return true if s1 and s2 are circular permutations of each other, otherwise false
 * @throws NullPointerException if s1 or s2 is null
 */
public static boolean isCircularPermutation(String s1, String s2) {
								int beginning = 0;
								int count = 0;
								// Checks if the strings are the ame one for one
								if(s1.equals(s2)) {
																return true;
								}

								// checks if the two strings are not the same length
								if(s1.length() != s2.length()) {
																return false;
								}
								// loop to find the beginning of the second string
								for(int i = 0; i < s1.length(); i++) {
																// checks for the beginning of the first string in the second string
																if(s1.charAt(0) == s2.charAt(i)) {
																								beginning = i;
																								break;
																}
								}

								// loops through the first string
								for(int i = 0; i < s1.length(); i++) {
																// checks whether the letters match
																if(s1.charAt(i)==s2.charAt((beginning+i) % s2.length()) ) {
																								count++;
																}

								}
								if(count == s1.length()) {
																return true;
								}
								return false;
}

}

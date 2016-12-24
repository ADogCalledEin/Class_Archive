package homework5;//NAME: Griffin Siadak

public class Homework5 {
	
	/***
	 * determines if a value is present in the matrix or not
	 * 
	 * 
	 * @param matrix NxN matrix where row values are increasing left to right and
	 *      column values are increasing from top to bottom
	 * @param search value
	 * @return returns true if the value is contained in the matrix, otherwise false
	 */

	public static boolean OrderedMatrixContains(int [][] matrix, int value) {

		int row = matrix.length - 1;  // start on the bottom left value of the matrix
		int col = 0;

		while((col < matrix[0].length ) && (row > -1)){ // while we're still in the matrix, do this

			if (matrix[row][col] == value){
				return true;
			}
			else if(matrix[row][col] > value){   // if the key is smaller than the value, shift up a row
				row = row - 1;
			}
			else if (matrix[row][col] < value){ // if the key is larger than the value, shift right a column
				col++;
			}

		}

		return false;
	}


}

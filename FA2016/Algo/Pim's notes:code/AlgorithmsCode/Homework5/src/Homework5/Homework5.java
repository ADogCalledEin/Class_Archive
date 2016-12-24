package Homework5;
// Homework 5 by Pim Trouerbach


public class Homework5 {

	public static boolean orderedMatrixContains(int[][] matrix, int value) {
		int row = 0;
		int col = matrix.length - 1;
		//int count = 0;

		while (row < matrix.length && col >= 0) {

			if (matrix[row][col] < value) {
				//System.out.println("moves down");
				//System.out.println(matrix[row][col]);
				row++;

			}
			if (matrix[row][col] > value) {
				//System.out.println("moves right");
				//System.out.println(matrix[row][col]);
				col--;

			}
			if(matrix[row][col] == value) {
				//System.out.println("Val found");
				//System.out.println(matrix[row][col]);
				return true;

			}
			//count++;
			//System.out.println("count is " + count);
		}
		return false;
	}
}
package homework3;

public class Homework3 {

	public static void sort(int [] a) {
		int N = a.length;
		int did_swap;

		do {
			did_swap = 0;
			for(int i = 1; i < N; i++){
				if (a[i-1] > a[i] ){
					int t = a[i];
					a[i] = a[i-1];
					a[i-1] = t;
					did_swap = 1;
				}
			}
		}while (did_swap == 1);
		
	}

	public static void main(String[] args){  //testing in main cuz whatever
		int[] b = {8,4,5,9,2,1,3,6,7};

		sort(b);

		for(int i = 0; i < b.length; i++){
			System.out.println(b[i]);
		}
	}
	
}

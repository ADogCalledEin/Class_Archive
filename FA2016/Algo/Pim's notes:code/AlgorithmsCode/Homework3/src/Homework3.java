
public class Homework3 {

	public static void sort(int [] a, int N) {
        int t;
        int did_swap;
        do {
            did_swap = 0;
            for (int i = 1; i < N; i++) { // FOR THIS TO WORK IT HAS TO BE i < N, NOT i < N-1
                if (a[i - 1] > a[i]) {
                    t = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = t;
                    did_swap = 1;
                }
            }
        }while(did_swap == 1);
    }
	
}

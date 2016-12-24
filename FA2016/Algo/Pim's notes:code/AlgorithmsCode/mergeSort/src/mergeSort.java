public class mergeSort{
    public static void main(String args[]){
        int i;
        double array[] = {12,9,4,99,120,1,3,10};
        System.out.println();
        mergeSort(array,0, array.length-1);

        // prints out the sorted array
        for(i = 0; i <array.length; i++) {
            System.out.print(array[i] + "  ");
        }
    }

    public static void mergeSort(double array[],int lo, int n){
        int low = lo;
        int high = n;

        // error handling purposes
        if (low >= high) {
            return;
        }
        // determines the middle of the array
        int middle = (low + high) / 2;
        // recursively calls mergesort until each section is a pair of two
        mergeSort(array, low, middle);
        mergeSort(array, middle + 1, high);

        // determines the end of low and the start of high
        int end_low = middle;
        int start_high = middle + 1;


        while ((lo <= end_low) && (start_high <= high)) {
            if (array[low] < array[start_high]) {
                low++;
            } else {
                double Temp = array[start_high];
                for (int k = start_high- 1; k >= low; k--) {
                    array[k+1] = array[k];
                }
                array[low] = Temp;
                low++;
                end_low++;
                start_high++;
            }
        }
    }
}
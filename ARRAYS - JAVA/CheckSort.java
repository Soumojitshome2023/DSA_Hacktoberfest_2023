public class CheckSort {
    static boolean isSorted(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true; 
    }

    public static void main(String args[]) {
        int arr1[] = {3, 5, 3, 8, 9, 1};
        System.out.print(isSorted(arr1));
    }
}

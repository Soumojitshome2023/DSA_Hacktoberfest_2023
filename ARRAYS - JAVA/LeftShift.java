public class LeftShift {
    static int[] shift(int arr[]) {
        int temp = arr[0];
        
        for (int i = 0; i < arr.length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        arr[arr.length - 1] = temp;
        
        return arr;
    }

    public static void main(String args[]) {
        int arr1[] = {1, 2, 3, 4, 5};
        int shiftedArr[] = shift(arr1);

        for (int element : shiftedArr) {
            System.out.print(element + " ");
        }
    }
}

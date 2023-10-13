public class MoveZeroes {
    static int[] move(int arr[]) {
        int zero = 0;
        int count = 0;
        int newLength = arr.length;
        int[] newArr = new int[newLength];
        
        for (int i = 0, j = 0; i < arr.length; i++) {
            if (arr[i] != zero) {
                newArr[j] = arr[i];
                j++;
                count++;
            }
        }
        
        for (int i = count; i < newLength; i++) {
            newArr[i] = zero;
        }
        
        return newArr;
    }
    
    public static void main(String args[]) {
        int arr1[] = {6, 1, 0, 3, 0, 5};
        int result[] = move(arr1);
        
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}

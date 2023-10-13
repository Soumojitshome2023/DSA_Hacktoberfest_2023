public class ContainDuplicates {
    static boolean Duplicate(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) { 
                if (arr[i] == arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String args[]) {
        int arr1[] = {1 , 1, 1 ,2, 2, 3, 4};
        System.out.println(Duplicate(arr1));
    }
}

public class MissingNumber {
    public static int missing(int arr[], int n){
    int arrsum = 0;
    for (int i = 0; i < arr.length; i++) {
        arrsum += arr[i];
    }
    int sum = (n * (n + 1)) / 2;
    int num = sum - arrsum;
    return num;
    }
    public static void main(String args[]) {
        int arr[] = {1,3,4,5};
        int n  = 5;
        System.out.println(missing(arr, n));
    }
}

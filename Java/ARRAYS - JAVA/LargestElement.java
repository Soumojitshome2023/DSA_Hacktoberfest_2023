public class LargestElement {
 
  static int Largest (int arr[]) {
    int max = arr[0];
    for (int i = 0 ; i < arr.length ; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;

  }
public static void main(String args[]) {
 
    int arr1[] =  {3,5,3,8,9,1};
   System.out.println(Largest(arr1));
}
}

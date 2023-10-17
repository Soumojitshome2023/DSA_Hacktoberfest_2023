
import java.util.Arrays;
 
class Main
{
    public static void merge(int[] arr, int[] aux, int low, int mid, int high)
    {
        int k = low, i = low, j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j]) {
                aux[k++] = arr[i++];
            }
            else {
                aux[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            aux[k++] = arr[i++];
        }
        for (i = low; i <= high; i++) {
            arr[i] = aux[i];
        }
    }
 
    public static void mergesort(int[] arr, int[] aux, int low, int high)
    {
        if (high <= low) {       
            return;
        }
 
        int mid = (low + ((high - low) >> 1));
       mergesort(arr, aux, low, mid);         
       mergesort(arr, aux, mid + 1, high);     
       merge(arr, aux, low, mid, high);        
    }
 
    public static boolean isSorted(int[] arr)
    {
        int prev = arr[0];
        for (int i = 1; i < arr.length; i++)
        {
            if (prev > arr[i])
            {
                System.out.println("MergeSort Fails!!");
                return false;
            }
            prev = arr[i];
        }
 
        return true;
    }
 
    // Implementation of merge sort algorithm in Java
    public static void main(String[] args)
    {
        int[] arr = { 12, 3, 18, 24, 0, 5, -2 };
        int[] aux = Arrays.copyOf(arr, arr.length);
 
        mergesort(arr, aux, 0, arr.length - 1);
 
        if (isSorted(arr)) {
            System.out.println(Arrays.toString(arr));
        }
    }
}

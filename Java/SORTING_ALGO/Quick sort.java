import java.util.Arrays;
 
class Main
{
    public static void swap (int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static int partition(int[] a, int start, int end)
    {
        int pivot = a[end];
        for (int i = start; i < end; i++)
        {
            if (a[i] <= pivot)
            {
                swap(a, i, pIndex);
                pIndex++;
            }
        }
 
        swap(a, end, pIndex);
        return pIndex;
    }

    public static void quicksort(int[] a, int start, int end)
    {
        if (start >= end) {
            return;
        }
        int pivot = partition(a, start, end);
        quicksort(a, start, pivot - 1);
        quicksort(a, pivot + 1, end);
    }
 
    // Java implementation of the Quicksort algorithm
    public static void main(String[] args)
    {
        int[] a = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
 
        quicksort(a, 0, a.length - 1);
        System.out.println(Arrays.toString(a));
    }
}

import java.io.IOException;

public class HeapSortTest {
	public static void main(String[] args) throws IOException {
		int[] num = { 0, 37, 25, 43, 65, 48, 84, 73, 18, 79, 56, 69, 32 };
		int n = 12;
		
		 System.out.println("Original array:");
	        for (int h = 1; h <= n; h++) {
				System.out.printf("%d ", num[h]);
	        }

		heapSort(num, n);

        System.out.println("\nSorted array:");
        for (int h = 1; h <= n; h++) {
        	System.out.printf("%d ", num[h]);
        }
	}

	public static void heapSort(int[] num, int n) {
		// sort num[1] to num[n]
		// convert the array to a heap
		for (int k = n / 2; k >= 1; k--)
			siftDown(num[k], num, k, n);
		for (int k = n; k > 1; k--) {
			int item = num[k]; // extract current last item
			num[k] = num[1]; // move top of heap to current last node
			siftDown(item, num, 1, k - 1); // restore heap properties from 1 to k-1
		}
	} // end heapSort

	public static void siftDown(int key, int[] num, int root, int last) {
		int bigger = 2 * root;
		while (bigger <= last) { // while there is at least one child
			if (bigger < last) // there is a right child as well; find the bigger
				if (num[bigger + 1] > num[bigger])
					bigger++;
			// 'bigger' holds the index of the bigger child
			if (key >= num[bigger])
				break;
			// key is smaller; promote num[bigger]
			num[root] = num[bigger];
			root = bigger;
			bigger = 2 * root;
		}
		num[root] = key;
	} // end siftDown
}

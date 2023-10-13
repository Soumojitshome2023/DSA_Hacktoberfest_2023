public class ConsecutiveOnes {
    static int Consecutive(int arr[]) {
        int var = 0;
        int max = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 1) {
                var++;
                max = Math.max(max, var);
            } else {
                var = 0;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] arr = {0, 1, 1, 0, 1, 1};
        System.out.println(Consecutive(arr));
    }
}

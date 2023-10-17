class MiddleElement {
    public static int middle(int arr[]){
        int totalsum = 0, leftsum = 0;  
        for (int i=0; i<arr.length; i++) {
            totalsum = totalsum + arr[i];
        }
        for (int i=0; i < arr.length; i++){
            totalsum= totalsum-arr[i];
            if (totalsum==leftsum){
                return i;
            }
            leftsum = leftsum+arr[i];
        }
        return -1;
    }
    public static void main(String args[]) {
        int arr[] = {2, 3, -1, 8, 4};
        System.out.print(middle(arr));
    }
}
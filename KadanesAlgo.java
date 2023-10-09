import java.util.Scanner;

public class KadanesAlgo{
    public static void main(String[] args) {
        int n;
         Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array");
        n=sc.nextInt();
        int [] a= new int[n];
        
        for (int i = 0;i<n ; i++){
            System.out.print("Enter element "+(i+1)+": ");
            a[i]=sc.nextInt();
            
        }
        System.out.println("The max subarray is "+maxsub(a));
                    
    }
    // create function  maxsubarray

     static int maxsub(int a[]){
                int max_so_far=a[0];
                int max_ending_here=0;
                for(int i=0;i<a.length;i++){
                    max_ending_here+=a[i];
                    if(max_ending_here>max_so_far){
                        max_so_far=max_ending_here;
                    }
                    if(max_ending_here<0){
                        max_ending_here=0;
                    }


                }
                return max_so_far;



        }

}
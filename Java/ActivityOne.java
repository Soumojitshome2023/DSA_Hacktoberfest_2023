// This is a program that tackles the fundamentals of a one-dimensional java array
import java.util.Scanner;
public class ActivityOne {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        while (true) {
            System.out.println("Enter the size of the array: ");
            int size = input.nextInt();

            int [] arrayMo = new int [size];
            System.out.print("Enter "+size+" integer values: \n"); 
             
            //loop to insert the values to the array
            for (int i = 0; i < arrayMo.length; i++) {
                //i=1
                System.out.print("Enter element at index "+i+": ");
                int element_1 = input.nextInt();
                arrayMo [i] = element_1;
                
            }
            //Printing the original Array
            System.out.println("\nOriginal Array:");
            for (int j = 0; j < arrayMo.length; j++) {
                System.out.print(arrayMo[j]+" ");
                
            } 

            //Reversing the array
            int simula = 0; //index 0 of the array
            int dulo = arrayMo.length - 1; //the last index of the array
    
                while (simula < dulo) {
                    int tmp = arrayMo[simula]; //initialize a container for the index 0
                    arrayMo[simula] = arrayMo[dulo]; //swap the elements by putting the value of the last index to the first one
                    arrayMo[dulo] = tmp; // now assign the value of the tmp variable to the last index
                    
                    simula++;
                    dulo--;
                //Due to the incrementing and decrementing of the above-mentioned variables, the loop will proceed until the condition is no longer true
            }
            
            //Printing the reversed Array
            System.out.println("\n\nReversed Array:");
            for (int i = 0; i < arrayMo.length; i++) {
                System.out.print(arrayMo[i]+" ");
            }    
            

            //Prompting the user if he/she wants to do the thing again
            int choice ;
            do {
                System.out.println("\n\nDo you want to proceed again?\n Press [1] if yes\n Press [0] if no");
                choice=input.nextInt();

                if (choice != 0 && choice != 1) {
                        System.out.println("\nYou've entered an invalid value");
                }
            } while (choice != 0 && choice !=1 );

            if (choice == 0) {
               break; 
            }
            //Wanna try again?
            // System.out.println("\n\nDo you want to proceed again?\n Press [1] if yes\n Press [0] if no");
            // int choice = input.nextInt();
            //
            //         if (choice == 1) {
            //            continue; 
            //         }
            //         else if (choice == 0) 
            //             break;
            //         else
            //             System.out.println("\nYou've entered an invalid value");
            //             break;
            //     
        }
        


        // //Reversing the contents of the array using a for loop

        // System.out.println("\nReversed Array:");
        //
        // int end = arrayMo.length;
        // for (int i = 0; i < end - 1; i++) {
        //     int temp = arrayMo[i];
        //     arrayMo[i] = arrayMo[end-1];
        //     arrayMo[end-1] = temp;
        //
        //     end--;
        // }
        // for (int i = 0; i < arrayMo.length; i++) {
        //     System.out.print(arrayMo[i]+" ");
        //     
        // }

         

    }
    
}

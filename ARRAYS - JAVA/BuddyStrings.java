import java.util.Arrays;

public class BuddyStrings {

    public static boolean canConvert(String s, String goal) {
        char[] k = s.toCharArray();
        char[] q = goal.toCharArray();
        
        for (int i = 0; i < k.length; i++) {
            for (int j = i + 1; j < k.length; j++) {
             
                char temp = k[i];
                k[i] = k[j];
                k[j] = temp;
                
                if (Arrays.equals(k, q)) {
                    return true;
                }

                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
            }
        }
        
        return false;
    }

    public static void main(String[] args) {
        String s = "aa";
        String goal = "aabn";

        if (canConvert(s, goal)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}

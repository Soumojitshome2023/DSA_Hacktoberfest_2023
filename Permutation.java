import java.util.ArrayList;
import java.util.List;
class Permutation {
    public static void main (String[] args) {
        System.out.println(new Permutation().find_permutation("String"));
    }
    public List<String> find_permutation(String S) {
        // Code here
        List<String> l=new ArrayList<>();
        List<Character> temp=new ArrayList<>();
        boolean arr[]=new boolean[S.length()];
        find(S,l,temp,arr);
        return l;
    }
    void find(String S,List<String> l,List<Character> temp,boolean arr[]){
        if(temp.size()==S.length()){
            String x="";
            for(char c:temp){
                x+=c;
            }
            l.add(x);
        }
        for(int i=0;i<S.length();i++){
            if(!arr[i]){
                arr[i]=true;
                temp.add(S.charAt(i));
                find(S,l,temp,arr); 
                temp.remove(temp.size()-1);
                arr[i]=false;
            }
        }
    }
}
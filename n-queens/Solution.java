import java.util.ArrayList;
import java.util.List;

class Solution {
    static List<List<String>> ans;
        
    public List<List<String>> solveNQueens(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++)
          sb.append(".");

        ArrayList<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
          list.add(sb.toString());
        
        ans = new ArrayList<>();
        solve(0, n, list);
        
        return ans;
    }
    
    public void solve(int r, int n, List<String> list) {
        if (r == n) {
            ans.add(new ArrayList<>(list));
            return;
        }
        
        for (int c = 0; c < n; c++)
            if (check(r, c, n, list)) {
                list.set(r, list.get(r).substring(0, c) + 'Q' + list.get(r).substring(c + 1));
                solve(r + 1, n, list);
                list.set(r, list.get(r).substring(0, c) + '.' + list.get(r).substring(c + 1));
            }
    }
    
    public boolean check (int r, int c, int n, List<String> list) {
        if (r >= n || c >= n)
            return false;
        
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
            if (list.get(i).charAt(j) == 'Q')
                return false;
        
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
            if (list.get(i).charAt(j) == 'Q')
                return false;
        
        for (int i = r - 1; i >= 0; i--)
            if (list.get(i).charAt(c) == 'Q')
                return false;
        
        for (int j = c - 1; j >= 0; j--)
            if (list.get(r).charAt(j) == 'Q')
                return false;
        
        return true;
    }
}
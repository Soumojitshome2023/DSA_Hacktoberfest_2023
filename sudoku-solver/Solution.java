class Solution {
    public void solveSudoku(char[][] board) {
        check = false;
        solveSudoku(board, 0, 0);
    }
    
    boolean check;
    
    public void solveSudoku(char[][] board, int i, int j) {
        if (i == board.length || check) {
            check = true;
            return;
        }
        
        int ni = 0, nj = 0;
        
        if (j == board[0].length - 1) {
            nj = 0;
            ni = i + 1;
        }
        else {
            nj = j + 1;
            ni = i;
        }
        
        if (board[i][j] != '.') {
            solveSudoku(board, ni, nj);
            return;
        }
        
        for (char k = '1'; k <= '9'; k++) 
            if (validMove(board, i, j, k)) {
                board[i][j] = k;

                solveSudoku(board, ni, nj); 

                if (check)
                    return;

                board[i][j] = '.';
            }
    }
    
    public boolean validMove(char[][] board, int i, int j, char num) {
        for (char c: board[i])
            if (num == c)
                return false;
        
        for (char[] c: board)
            if (c[j] == num)
                return false;
        
        for (int k = i - i % 3, m = k; k < m + 3; k++) 
            for (int l = j - j % 3, n = l; l < n + 3; l++) 
                if (num == board[k][l]) 
                    return false;
        
        return true;
    }
}
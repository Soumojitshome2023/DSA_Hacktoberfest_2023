class Solution {
public:
    bool check(vector<vector<char>> &board,int i,int j,int c){
        for(int k=0;k<9;k++){
            if(board[k][j]==c)
                return false;
            if(board[i][k]==c)
                return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==c)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(check(board,i,j,c)){
                            board[i][j]=c;
                        if(solve(board)==true)
                            return true;
                        else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    void solve(int col,vector<vector<string>> &san,vector<string> &desh,vector<int> &left,vector<int> &lower, vector<int> &upper,int n){
        if(col==n)
            san.push_back(desh);
        for(int row=0;row<n;row++){
            if(left[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0){
                desh[row][col]='Q';
                left[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                solve(col+1,san,desh,left,lower,upper,n);
                desh[row][col]='.';
                left[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> san;
        vector<string> desh(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            desh[i]=s;
        vector<int> left(n,0),lower(2*n-1,0),upper(2*n-1,0);
        solve(0,san,desh,left,lower,upper,n);
        return san;
    }
};

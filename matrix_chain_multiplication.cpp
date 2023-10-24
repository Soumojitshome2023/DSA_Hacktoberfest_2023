Minimum Score Triangulation of Polygon - leetcode;
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/


//recursion
int mcm(int i, int j, vector<int>& values){
        if(i+1==j){
            return 0;
        }
        int res=INT_MAX;
        
        for(int k=i+1;k<j;k++){
            
            res=min(res,mcm(i,k,values)+mcm(k,j,values)+values[i]*values[k]*values[j]);
            
        }
        
        return res;
    }
    
//dp

int mcm(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> ans(n,vector<int> (n,0));
        
        for(int gap=2;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j=i+gap;
                ans[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]+(values[i]*values[k]*values[j]));
                    //ans[i][j] ka mtlb array ki i to j length par minimum multiplication
                }
            }
        }
        
        return ans[0][n-1];
    }


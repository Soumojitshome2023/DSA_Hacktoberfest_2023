#include <bits/stdc++.h> 
using namespace std; 

int DP(vector<int>& nums, int index, vector<int>&dp, int last){

    if(index >= last) //if index out of bounds return 0
        return 0;

    if(dp[index] != -1) //if sub problem was already calculated before
        return dp[index];

    // max of cases when u either rob this house and skip the next  or don't rob this house and go to the next house
    return dp[index] = max(nums[index]+DP(nums,index+2,dp,last),DP(nums,index+1,dp,last));
}

int rob(vector<int>& nums) {

    vector<int>dp(nums.size()+1,-1); //initialize dp array

    // split array into 2 parts, [0 .. n-1] [1 .. n] and apply house robber logic and take maximum
    return max(DP(nums,0,dp,nums.size()-1),DP(nums,1,dp,nums.size())); // use recursion with memoization
}
  

int main() 
{ 
    vector<int> nums = {1,2,3,1}; //input array

    int maxAmount = rob(nums);
    cout << "Maximum amount that can be robbed: " << maxAmount << endl;
    return 0;
}

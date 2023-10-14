#include <bits/stdc++.h> 
using namespace std; 

vector<int> solve(vector<int>& nums) {
    int n = nums.size();

    vector<int> left(n);
    vector<int> right(n);
    
    //prefix product
    left[0] = 1; 
    for(int i = 1; i < nums.size(); i++){
        left[i] = left[i - 1] * nums[i - 1];
    }
    
    //suffix product
    right[n - 1] = 1; 
    for (int j = n - 2; j >= 0; j--) {
        right[j] = right[j + 1] * nums[j + 1];
    }
    
    vector<int> res(n);

    for (int k = 0; k < n; k++) {
        res[k]= left[k] * right[k];
    }
    
    return res;
}

int main() 
{ 
    vector<int> nums = {1, 2, 3, 1, 5};
    int target = 5;

    vector<int> result = solve(nums); // each index of result is product of array except nums[index]

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0; 
}


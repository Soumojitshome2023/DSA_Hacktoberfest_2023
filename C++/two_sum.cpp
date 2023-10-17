#include <bits/stdc++.h> 
using namespace std; 

vector<int> twoSum (vector<int>& nums, int target) {

    unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int difference = target - nums[i];
        if ( numMap.count(difference) ) {
            return { numMap[difference], i };
        }
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

int main() 
{ 
    vector<int> nums = {1, 2, 3, 1, 5};
    int target = 5;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices of the two numbers that sum to the target: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
  
    return 0; 
}


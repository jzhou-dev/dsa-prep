#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
       vector<bool> used(nums.size(), false);
       vector<int> permutation;
       backtrack(nums, used, permutation);
       return result; 
    }
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& permutation) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                permutation.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, used, permutation);
                used[i] = false;
                permutation.pop_back();
            }
        }
    }
};
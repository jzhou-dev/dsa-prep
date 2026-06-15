#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
        backtrack(nums, permutation, used);
        return result;
        
    }
    void backtrack(vector<int>& nums, vector<int>& permutation, vector<bool>& used) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }
        int i = 0;
        while (i < nums.size()) {
            if (!used[i]) {
                permutation.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, permutation, used);
                permutation.pop_back();
                used[i] = false;
                while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
                    i++; 
                }
            }
            i++;
        }
    }
};
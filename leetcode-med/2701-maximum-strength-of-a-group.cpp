#include "leet.h"

class Solution {
public:
    long long result = LLONG_MIN;
    long long maxStrength(vector<int>& nums) {
        vector<int> group;
        backtrack(nums, group, 0, 0);
        return result;    
    }
    void backtrack(vector<int>& nums, vector<int>& group, int index, long long strength) {
        if (index == nums.size()) {
            if (group.size() > 0) {
                result = max(strength, result);
            }
            return;
        }
        group.push_back(nums[index]);
        if (group.size() == 1) {
            backtrack(nums, group, index+1, nums[index]);
        } else {
            backtrack(nums, group, index+1, strength * nums[index]);
        }
        group.pop_back();
        backtrack(nums, group, index+1, strength);
    }
};
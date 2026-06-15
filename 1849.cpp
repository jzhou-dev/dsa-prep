#include "leet.h"

class Solution {
public:
    bool splitString(string s) {
        vector<long long> nums;
        return backtrack(s, nums, 0);    
    }
    bool backtrack(string s, vector<long long>& nums, int i) {
        if (i > s.size() - 1) {
            if (nums.size() >= 2) {
                return true;
            }
            return false;
        }
        for (int j = i; j < s.size(); j++) {
            long long num = stoll(s.substr(i, j-i+1));
            nums.push_back(num);
            if (valid(nums)) {
                if (backtrack(s, nums, j+1)) {
                    return true;
                }
            }
            nums.pop_back();
        }
        return false;
    }
    bool valid(vector<long long>& nums) {
        if (nums.size() > 1) {
            if (nums[nums.size()-1] < nums[nums.size()-2] && nums[nums.size()-2] - nums[nums.size()-1] == 1) {
                return true;
            } else {
                return false;
            }
        } 
        return true;
    }
};
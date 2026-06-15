#include "leet.h"

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum = {0};
        vector<int> rightSum(nums.size());
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum.push_back(leftSum.back() + nums[i]);
        } 
        for (int i = nums.size()-2; i >= 0; i--) {
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(abs(leftSum[i] - rightSum[i]));
        }
        return result;
    }
};
#include "leet.h"

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> maxNums;
        vector<int> minNums(nums.size(), INT_MAX);
        int beauty = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxNums.empty()) {
                maxNums.push_back(nums[i]);
            } else {
                if (maxNums.back() < nums[i]) {
                    maxNums.push_back(nums[i]);
                } else {
                    maxNums.push_back(maxNums.back());
                }
            }

        } 
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                minNums[i] = nums[i];
            } else {
                if (minNums[i+1] < nums[i]) {
                    minNums[i] = minNums[i+1];
                } else {
                    minNums[i] = nums[i];
                }
            }
        }
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > maxNums[i-1] && nums[i] < minNums[i+1]) {
                beauty += 2;
            } else if (nums[i] > nums[i-1] && nums[i] < nums[i+1]) {
                beauty += 1;
            }
        }
        return beauty;
    }
};
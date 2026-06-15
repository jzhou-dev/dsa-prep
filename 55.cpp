#include "leet.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size()-1; i++) {
          maxPos = max(maxPos, i + nums[i]);
          if (maxPos >= nums.size()-1) {
            return true;
          }
          if (nums[i] == 0 && maxPos <= i) {
            return false;
          }
        }
        return true;
    }
};

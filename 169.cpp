#incldue "leet.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      pair<int, int> count;
      for (int i = 0; i < nums.size(); i++) {
        if (count.second == 0) {
          count = {nums[i], 0};
        }
        if (nums[i] == count.first) {
          count.second++;
        } else {
          count.second--;
        }
      }
      return count.first;
    }
};

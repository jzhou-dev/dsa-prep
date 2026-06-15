#inclue "leet.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      if (nums.size() % 2 == 0) {

        int j = 0;
        int swap = nums[0];
        for (int i = 0; i < ceil(nums.size()/2); i++) {
          j = (j + k) % nums.size();
          int temp = nums[j];
          nums[j] = swap;
          swap = temp;
        }
        j = 1;
        swap = nums[1];
        for (int i = 0; i < nums.size() / 2; i++) {
          j = (j + k) % nums.size();
          int temp = nums[j];
          nums[j] = swap;
          swap = temp;
        }
      } else {
        int j = 0;
        int swap = nums[0];
        for (int i = 0; i < nums.size(); i++) {
          j = (j + k) % nums.size();
          int temp = nums[j];
          nums[j] = swap;
          swap = temp;
        }
      }
    }
};

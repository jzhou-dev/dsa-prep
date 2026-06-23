#include "../leet.h"

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int> nums, int k) {
    std::unordered_map<int, int> store;
    for (int i = 0; i < nums.size(); ++i) {
      if (store.find(nums[i]) != store.end() && abs(i - store[nums[i]]) <= k) {
        return true;
      }
      store[nums[i]] = i;
    }
    return false;
  }
};

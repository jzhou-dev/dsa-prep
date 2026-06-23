#include "../leet.h"

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> store;
    for (int i = 0; i < nums.size(); ++i) {
      if (store.find(target - nums[i]) != store.end()) {
        return {store[target - nums[i]], i};
      }
      store[nums[i]] = i;
    }
    return {};
  }
};

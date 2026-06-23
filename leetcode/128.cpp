#include "../leet.h"

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> store(nums.begin(), nums.end());
    std::unordered_set<int> start;
    int max_len = 0;
    for (const auto &num : nums) {
      if (store.find(num - 1) == store.end()) {
        start.insert(num);
      }
    }
    for (const auto &i : start) {
      int curr_len = 0;
      int curr_num = i;
      while (store.find(curr_num) != store.end()) {
        curr_len++;
        curr_num++;
      }
      max_len = std::max(max_len, curr_len);
    }
    return max_len;
  }
};

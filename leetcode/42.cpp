#include "leet.h"

class Solution {
public:
  int trap(vector<int>& height) {
    vector<int> left_max(height.size(), 0);
    vector<int> right_max(height.size(), 0);
    for (int i = 0; i < height.size() ; i++) {
      if (i == 0) {
        left_max[i] = height[i];
      } else {
        int max_height = height[i] > left_max[i-1] ? height[i] : left_max[i-1];
        left_max[i] = max_height;
      }
    }
    for (int i = height.size()-1 ; i >= 0; i--) {
      if (i == height.size()-1) {
        right_max[i] = height[i];
      } else {
        int max_height = height[i] > right_max[i+1] ? height[i] : right_max[i+1];
        right_max[i] = max_height;
      }
    }
    int water = 0;
    for (int i = 0; i < height.size(); i++) {
      water += min(left_max[i], right_max[i]) - height[i];
    }
    return water;
  }
};

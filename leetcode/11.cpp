#include "leet.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0;
        int r = height.size()-1;
        while (l < r) {
          int curr_area = min(height[l], height[r]) * (r - l);
          area = max(area, curr_area);
          if (height[l] < height[r]) {
            l++;
          } else {
            r--;
          }
        }
        return area;
    }
};

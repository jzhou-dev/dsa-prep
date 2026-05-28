#include "leet.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left_bounds;
        vector<int> right_bounds;
        vector<int> stack;
        for (int i = 0; i < heights.size(); i++) {
            while (stack.size() > 0 && heights[stack.back()] >= heights[i]) {
                stack.pop_back();
            }
            if (stack.size() == 0) {
                left_bounds.push_back(0);
            } else {
                left_bounds.push_back(stack.back() + 1);
            }
            stack.push_back(i);
        }
        stack.clear();
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (stack.size() > 0 && heights[stack.back()] >= heights[i]) {
                stack.pop_back();
            }
            if (stack.size() == 0) {
                right_bounds.push_back(heights.size());
            } else {
                right_bounds.push_back(stack.back());
            }
            stack.push_back(i);
        }
        int result = 0;
        for (int i = 0; i < left_bounds.size(); i++) {
            int area = (right_bounds[right_bounds.size() - i - 1] - left_bounds[i]) * heights[i];

            if (area > result) {
                result = area;
            }
        }
        return result;
    }
};

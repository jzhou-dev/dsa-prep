#include "leet.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int peak = 0;
        int peak_index = 0;
        stack<int> mountainFront;
        stack<int> mountainBack;
        long long size = 0;
        for (int i = 0; i < heights.size(); i++) {
            peak = heights[i];
            peak_index = i;
            for (int i = 0; i <= peak_index; i++) {
                mountainFront.push(heights[i]);
            }
            for (int i = heights.size() - 1; i > peak_index; i--) {
                mountainBack.push(heights[i]);
            }
            int temp_peak = peak;
            long long temp_size = 0;
            while (mountainFront.size() > 0) {
                int height = mountainFront.top();
                if (height <= temp_peak) {
                    temp_peak = height;
                    temp_size += height;
                } else {
                    temp_size += temp_peak;
                }
                mountainFront.pop();
            }
            temp_peak = peak;
            while (mountainBack.size() > 0) {
                int height = mountainBack.top();
                if (height <= temp_peak) {
                    temp_peak = height;
                    temp_size += height;
                } else {
                    temp_size += temp_peak;
                }
                mountainBack.pop();
            }
            if (temp_size > size) {
                size = temp_size;
            }
        }
        return size;
    }
};
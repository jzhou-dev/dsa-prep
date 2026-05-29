#include "leet.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()) {
            int profit = prices[r] - prices[l];
            if (profit < 0) {
                l = r;
            } else if (profit > max) {
                max = profit;
            }
            r++;
        }
        return max;
        
    }
};

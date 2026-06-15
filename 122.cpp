#include "leet.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int profit = 0;
        while (r < prices.size()) {
            int currProfit = prices[r] - prices[l];
            if (currProfit > 0) {
                profit += currProfit;
            }
            l++;
            r++;
        }
        return profit;
    }
};


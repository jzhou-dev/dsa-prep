#include "leet.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int profit = 0;
        while (sell < prices.size() && buy < prices.size()) {
          int currProfit = prices[sell] - prices[buy];
          if (currProfit < 0) {
            buy++;
          } else {
            profit = max(profit, currProfit);
            sell++;
          }
        }
        return profit;
    }
};

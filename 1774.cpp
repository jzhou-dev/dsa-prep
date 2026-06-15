#include "leet.h"

class Solution {
public:
    int result;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        result = baseCosts[0];
        vector<int> toppingUsed(toppingCosts.size(), 0);
        for (int i = 0; i < baseCosts.size(); i++) {
            backtrack(toppingCosts, toppingUsed, baseCosts[i], target, 0);
        }
        return result; 
    }
    void backtrack(vector<int>& toppingCosts, vector<int>& toppingUsed, int cost, int target, int start) {
        if (abs(target-cost) < abs(target-result)) {
            result = cost;
        } else if (abs(target-cost) == abs(target-result)) {
            if (cost < result) {
                result = cost;
            }
        }
        if (cost >= target) {
            return;
        }

        for (int i = start; i < toppingCosts.size(); i++) {
            if (toppingUsed[i] < 2) {
                toppingUsed[i]++;
                backtrack(toppingCosts, toppingUsed, cost + toppingCosts[i], target, i);
                toppingUsed[i]--;
            }
        }
    }
};
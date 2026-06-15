#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        backtrack(k, n, 1, combination);
        return result;
    }
    void backtrack(int k, int n, int start, vector<int>& combination) {
        if (combination.size() == k) {
            if (n == 0) {
                result.push_back(combination);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            combination.push_back(i);
            backtrack(k, n-i, i+1, combination);
            combination.pop_back();
        }
    }
};
#include "leet.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice = 0;
        int bob = 0;
        unordered_set<int> bobs;
        for (const auto& a: aliceSizes) {
            alice += a;
        }
        for (const auto& b: bobSizes) {
            bob+=b;
            bobs.insert(b);
        }
        for (const auto& a: aliceSizes) {
            int need = (alice-bob-(2*a)) / -2;
            if (bobs.count(need)) {
                return {a, need};
            }
        }
        return {};
    }
};
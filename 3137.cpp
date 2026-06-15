#include "leet.h"

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> substrings;
        int max_freq = 0;
        for (int i = 0; i < word.size(); i+=k) {
            string sub = word.substr(i, k);
            if (substrings.find(sub) != substrings.end()) {
                substrings[sub]++;
            } else {
                substrings[sub] = 1;
            }
            if (substrings[sub] > max_freq) {
                max_freq = substrings[sub];
            }
        }
        return (word.size() - (max_freq*k))/k;
    }
};
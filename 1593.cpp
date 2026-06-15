#include "leet.h"

class Solution {
public:
    unordered_set<string> seen;
    int maxCount = 0;
    int maxUniqueSplit(string s) {
      string substring = "";
      maxUniqueSplit(s, 0, 0);
      return maxCount;
    }
    void maxUniqueSplit(string& s, int count, int start) {
        if (start > s.size()) {
            maxCount = max(maxCount, count);
            return;
        }
        string substring = "";
        for (int i = start; i < s.size(); i++) {
            substring.push_back(s[i]);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxUniqueSplit(s, count+1, i+1);
                seen.erase(substring);
            }
        }
    }
};
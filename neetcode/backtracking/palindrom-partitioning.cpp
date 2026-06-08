#include "leet.h"

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> curr_partition;
        vector<bool> used(s.size(), false);
        backtrack(s, curr_partition, 0);
        return result;
    }
    void backtrack(string& s, vector<string>& part, int j) {
        if (j >= s.size()) {
            result.push_back(part);
            return;
        }
        for (int i = j; i < s.size(); i++) {
            if (isPal(s, j, i)) {
                part.push_back(s.substr(j, i-j+1));
                backtrack(s, part, i+1);
                part.pop_back();
            }
        }
    }
    bool isPal(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

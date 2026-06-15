#include "leet.h"

class Solution {
public:
    string result;
    string smallestNumber(string pattern) {
        string num = "";
        vector<bool> used(9, false);
        backtrack(pattern, 0, num, used);
        return result;    
    }
    bool backtrack(string& pattern, int index, string& num, vector<bool>& used) {
        if (num.size() == pattern.size() + 1) {
            result = num;
            return true;
        }
        for (int i = 0; i < 9; i++) {
            if (!used[i]) {
                num.push_back((i+1) + '0');
                used[i] = true;
                if (index == 0 || valid(pattern[index-1], num)) {
                    if (backtrack(pattern, index+1, num, used)) {
                        return true;
                    }   
                }
                num.pop_back();
                used[i] = false;
            }
        }
        return false;
    }
    bool valid(char& s, string& num) {
        if (num.size() > 1) {
            if (s == 'I') {
                if (num[num.size()-2] - '0' < num[num.size() - 1] - '0') {
                    return true;
                }
            } else {
                if (num[num.size()-2] - '0' > num[num.size()-1] - '0') {
                    return true;
                }
            }
        } else {
            return true;
        }
        return false;
    }
};
#include "leet.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> s1_freq;
        unordered_map<char, int> s2_freq; 
        for (int i = 0; i < s1.size(); i++) {
            s1_freq[s1[i]]++;
            s2_freq[s2[i]]++;
        }
        if (s1_freq == s2_freq) {
                return true;
        }
        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {
            s2_freq[s2[r]]++;
            s2_freq[s2[l]]--;
            if (s2_freq[s2[l]] == 0) {
                s2_freq.erase(s2[l]);
            }
            l++;
            if (s1_freq == s2_freq) {
                return true;
            }
        }
        return false;
    }
};
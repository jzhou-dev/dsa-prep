#include "leet.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_els;
        unordered_map<char, int> t_els;
        string result = "";
        for (char c: t) {
            t_els[c]++;
        }
        int have = 0;
        int need = t_els.size();
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            s_els[s[r]]++;
            if (t_els.count(s[r]) && s_els[s[r]] == t_els[s[r]]) {
                have++;
            }
            cout << have << endl;
            while (have == need) {
                if (result == "" || r-l+1 < result.size()) {
                    result = s.substr(l, r-l+1);
                }
                s_els[s[l]]--;
                if (t_els.count(s[l]) && s_els[s[l]] < t_els[s[l]]) {
                    have--;
                }
                l++;
            }
            r++;
        }
       
        return result;
    }
};

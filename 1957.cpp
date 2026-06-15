#include "leet.h"
class Solution {
public:
    string makeFancyString(string s) {
        int i = 0;
        int j = 3;
        while (j < s.length()) {
            bool del = true;
            for (int x = i; x < j - 1; x++) {
                if (s[x] != s[x+1]) {
                    del = false;
                    break;
                }
            }
            if (del) {
                s.erase(j-1, 1);
            } else {
                j++;
                i++;
            }
            cout << s << endl;
        }
        return "HI";
    }
};
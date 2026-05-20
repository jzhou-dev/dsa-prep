#include "leet.h"

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                num++;
            }
        }
        for (int i = 0; i < s.length()-1; i++) {
            if (i < num-1) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        s[s.length()-1] = '1';
        return s;

    }
};
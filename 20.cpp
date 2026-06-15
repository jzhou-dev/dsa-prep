#include "leet.h"

class Solution {
public:
    bool isValid(string s) {
        set<char> pars = {'(', '[', '{'};
        map<char, char> endPars = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> els;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                els.push(s[i]);
            } else if (els.empty() ||
                      (s[i] == ')' && els.top() != '(') ||
                      (s[i] == ']' && els.top() != '[') ||
                      (s[i] == '}' && els.top() != '{')) {
                return false;
            } else {
                els.pop();
            }   
        }
        return els.empty();
    }
};
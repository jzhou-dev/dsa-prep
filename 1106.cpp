#include "leet.h"

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        stack<char> expressions;
        stack<char> bools;
        while (i < expression.size()) {
            if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!') {
                expressions.push(expression[i]);
            } else if (expression[i] == '(' || expression[i] == 't' || expression[i] == 'f') {
                bools.push(expression[i]);
            } else if (expression[i] == ')') {
                if (expressions.top() == '&') {
                    bool curr = true;
                    while (bools.top() != '(') {
                        if (bools.top() == 'f') {
                            curr = false;
                        }
                        bools.pop();
                    }
                    bools.pop();
                    bools.push(curr ? 't' : 'f');
                } else if (expressions.top() == '|') {
                    bool curr = false;
                    while (bools.top() != '(') {
                        if (bools.top() == 't') {
                            curr = true;
                        }
                        bools.pop();
                    }
                    bools.pop();
                    bools.push(curr ? 't' : 'f');
                } else {
                    char topValue = bools.top();
                    bools.pop();
                    bools.pop(); 
                    bool curr = (topValue == 't') ? false : true;
                    bools.push(curr ? 't' : 'f');
                }
                expressions.pop();
            }
            i++;
        }
        return bools.top() == 't' ? true : false;
    }
};
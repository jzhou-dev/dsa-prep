#include "leet.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        int result = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                int n2 = store.top();
                store.pop();
                int n1 = store.top();
                store.pop();
                if (tokens[i] == "+") {
                    store.push(n1+n2);
                } else if (tokens[i] == "-") {
                    store.push(n1-n2);
                } else if (tokens[i] == "*") {
                    store.push(n1*n2);
                } else {
                    store.push(n1/n2);
                }
            } else {
                store.push(stoi(tokens[i]));
            }
        }
        return store.top();
    }
};

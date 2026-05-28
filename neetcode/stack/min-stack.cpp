#include "leet.h"

class MinStack {
public:
    vector<int> elements;
    stack<int> minElements;
    int size;
    MinStack() {
        elements = {};
        minElements = {};
        size = 0;
    }
    
    void push(int val) {
        size++;
        if (size > elements.size()) {
            elements.push_back(val);
        } else {
            elements[size-1] = val;
        }
        if (minElements.size() == 0) {
            minElements.push(val);
        } else {
            if (val <= minElements.top()) {
                minElements.push(val);
            }
        }
    }
    
    void pop() {
        if (minElements.top() == elements[size-1]) {
            minElements.pop();
        }
        size--;
    }
    
    int top() {
        return elements[size-1];
    }
    
    int getMin() {
        return minElements.top();
    }
};

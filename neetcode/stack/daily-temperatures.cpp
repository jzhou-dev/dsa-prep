#include "leet.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> store;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            if (store.size() == 0) {
                store.push({temperatures[i], i});
            } else {
                while (store.size() > 0 && store.top().first < temperatures[i]) {
                    result[store.top().second] = i - store.top().second;
                    store.pop();
                }
                store.push({temperatures[i], i});
            }
        }
        return result;
    }
};

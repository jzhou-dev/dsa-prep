#include "leet.h"

class Solution {
public:
    double time(pair<int, int> car, int target) {
        return 1.0 * (target - car.first) / car.second;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack<double> store;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        for (int i = cars.size() - 1; i >= 0; i--) {
            if (store.size() == 0) {
                store.push(1.0 * (target - cars[i].first) / cars[i].second);
            } else {
                if (1.0 * (target - cars[i].first) / cars[i].second > store.top()) {
                    store.push(1.0 * (target - cars[i].first) / cars[i].second);
                }
            }
        }
        return store.size();
    }
};





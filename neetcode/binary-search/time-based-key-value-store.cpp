#include "leet.h"


class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        map = {};
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) != map.end()) {
            int low = 0;
            int high = map[key].size() - 1;
            pair<int, string> max;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (map[key][mid].first <= timestamp) {
                    low = mid + 1;
                    if (map[key][mid].first > max.first) {
                        max = map[key][mid];
                    }
                } else {
                    high = mid - 1;
                }
            }
            return max.second;
        } else {
            return "";
        }
    }
};



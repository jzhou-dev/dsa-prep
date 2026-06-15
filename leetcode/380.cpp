#include "leet.h"

class RandomizedSet {
public:
    unordered_map<int, int> store;
    vector<int> elements;
    RandomizedSet() {
      elements = {};
      store = {};
    }
    
    bool insert(int val) {
      if (store.count(val) != 0) {
        return false;
      }
      elements.push_back(val);
      store.insert({val, elements.size()-1});
      return true;
    }
    
    bool remove(int val) {
      if (store.count(val) == 0) {
        return false;
      }
      int index = store[val];
      store.erase(val);
      if (index != elements.size()-1) {
        store[elements[elements.size()-1]] = index;
        elements[index] = elements[elements.size()-1];
      }
      elements.pop_back();
      return true;
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(0, elements.size()-1);
        int index = distrib(gen);
        return elements[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

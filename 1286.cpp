#include "leet.h"

class CombinationIterator {
public:
    vector<string> combinations;
    int index = 0;
    CombinationIterator(string characters, int combinationLength) {
        string combination = "";
        backtrack(characters, combinationLength, combination, 0);
    }

    void backtrack(string& characters, int combinationLength, string& combination, int i) {
        if (combination.size() == combinationLength) {
            combinations.push_back(combination);
            return;
        }
        if (i > characters.size() - 1) {
            return;
        } 
        combination.push_back(characters[i]);
        backtrack(characters, combinationLength, combination, i+1);
        combination.pop_back();
        backtrack(characters, combinationLength, combination, i+1);
    }
    
    string next() {
        string result = "";
        if (index < combinations.size()) {
            result = combinations[index];
            index++;
        }
        return result; 
    }

    bool hasNext() {
        if (index > combinations.size() - 1) {
            return false;
        }        
        return true;
    }
};
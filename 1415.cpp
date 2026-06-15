#include "leet.h"

class Solution {
public:
    string result = "";
    string getHappyString(int n, int k) {
        string characters = "abc";
        string happyString = "";
        getHappyString(n, k, happyString, characters);
        return result;
    }
    void getHappyString(int n, int& k, string& happyString, string& characters) {
        if (happyString.size() == n) {
            k--;
            if (k == 0) {
                result = happyString;
            }
            return;
        }
        for (int i = 0; i < characters.size(); i++) {
            if (happyString.empty() || happyString.back() != characters[i]) {
                happyString.push_back(characters[i]);
                getHappyString(n, k, happyString, characters);
                happyString.pop_back();
            }
        }
    }

    
};
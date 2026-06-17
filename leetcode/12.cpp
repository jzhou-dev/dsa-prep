#include "leet.h";

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < values.size(); i++) {
          int div = num / values[i];
          num -= div * values[i];
          for (int x = 0; x < div; x++) {
            result+=symbols[i];
          }
        }
        return result;
    }
};


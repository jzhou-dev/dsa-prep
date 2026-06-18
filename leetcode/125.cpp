#include "leet.h"

class Solution {
public:
    bool isPalindrome(string s) {
      string filtered = "";
      for (char c : s) {
        if (isalnum(c)) {
          filtered.push_back(tolower(c));
        }
      }
      int l = 0;
      int r = filtered.size()-1;
      while (l < r) {
        if (filtered[l] != filtered[r]) {
          return false;
        }
        l++;
        r--;
      }
      return true;
    }
};

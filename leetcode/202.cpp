#include "../leet.h"

class Solution {
public:
  bool isHappy(int n) {
    std::unordered_set<int> store;
    while (n != 1) {
      int temp = sumSquareDigits(n);
      if (store.find(temp) != store.end()) {
        return false;
      } else {
        store.insert(temp);
        n = temp;
      }
    }
    return true;
  }
  int sumSquareDigits(int n) {
    int total = 0;
    while (n != 0) {
      int digit = n % 10;
      n = n / 10;
      total += digit * digit;
    }
    return total;
  }
};

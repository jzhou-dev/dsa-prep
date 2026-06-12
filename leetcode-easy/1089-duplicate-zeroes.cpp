#include "leet.h"

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        int j = 0;
        while (i < arr.size()) {
            if (arr[i] == 0) {
                j = i;
                int temp = arr[j];
                while (j < arr.size() - 1) {
                    int temp2 = arr[j+1];
                    arr[j+1] = temp;
                    temp = temp2;
                    j++;
                }
                i++;
            }
            i++;
        }
    }
};
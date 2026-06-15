#include "leet.h"

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int low = squares[0][1];
        int high = 0;
        for (int i = 0; i < squares.size(); i++) {
            int y = squares[i][1];
            if (y < low) {
                low = y;
            }
            if (y > high) {
                high = y;
            }
        }

        while (low < high) {
            double mid = low + ((high - low) * 1.0) / 2;
            double h_above = 0;
            double h_below = 0;
            calculateHeight(mid, squares, h_below, h_above);
            if (h_above == h_below) {
                return mid;
            } else if (h_above > h_below) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
    void calculateHeight(int mid, vector<vector<int>> &squares, double &h_below, double &h_above) {

    }
};
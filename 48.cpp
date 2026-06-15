#include "leet.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < (matrix.size() + 1) / 2; i++) {
            for (int j = 0; j < matrix.size() - (i * 2) - 1; j++) {
                int tl = matrix[i][i+j];
                int tr = matrix[i+j][matrix.size() - i - 1];
                int bl = matrix[matrix.size()-i-1-j][i];
                int br = matrix[matrix.size()-i - 1][matrix.size()-i-j-1];
                matrix[i+j][matrix.size() - i - 1] = tl;
                matrix[matrix.size()-i - 1][matrix.size()-i-j-1] = tr;
                matrix[matrix.size()-i-1-j][i] = br;
                matrix[i][i+j] = bl; 
            }
        }
    }
};
#include "leet.h"

class Solution {
public:
    vector<vector<char>> board;
    string word;
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool backtrack(int row, int col, int index) {
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#', board[row][col] != word[index]) {
            return false;
        }
        char c = board[row][col];
        board[row][col] = '#';
        bool result = backtrack(row+1, col, index + 1) || backtrack(row, col+1, index+1) || backtrack(row-1, col, index+1) || backtrack(row, col-1, index+1);
        board[row][col] = c;
        return result;
    }
};

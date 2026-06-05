#include "leet.h"

struct Node {
    Node* nodes[26];
    bool EOW;
    vector<string> words;
    Node() {
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
        EOW = false;
        words = {};
    }
    void add(string word) {
        Node* curr = this;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->nodes[word[i] - 'a']) {
                curr->nodes[word[i] - 'a'] = new Node();
            }
            curr = curr->nodes[word[i] - 'a'];
        }
        curr->EOW = true;
        curr->words.push_back(word);
    }
};
class Solution {
public:
    vector<string> result;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* head = new Node();
        for (const auto& word: words) {
            head->add(word);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtrack(board, head, i, j, 0);
            }
        }
        return result;
    }
    void backtrack(vector<vector<char>>& board, Node* head, int row, int col, int index) {
        if (head->EOW) {
            for (const auto& word: head->words) {
                result.push_back(word);
            }
            head->words.clear();
            head->EOW = false;
        }
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || !head->nodes[board[row][col] - 'a'] || board[row][col] == '#') {
            return;
        }
        head = head->nodes[board[row][col] - 'a'];
        char temp = board[row][col];
        board[row][col] = '#';
        backtrack(board, head, row+1, col, index+1);
        backtrack(board, head, row, col+1, index+1);
        backtrack(board, head, row-1, col, index+1);
        backtrack(board, head, row, col-1, index+1);
        board[row][col] = temp;
        return;
    }
};

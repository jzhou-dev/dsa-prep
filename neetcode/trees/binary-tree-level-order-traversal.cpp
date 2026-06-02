#include "leet.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> result;
        helper(root, level, result);
        return result;
    }
    void helper(TreeNode* root, int level, vector<vector<int>>& result) {
        if (!root) {
            return;
        }
        if (level+1 > result.size()) {
            result.push_back({root->val});
        } else {
            result[level].push_back(root->val);
        }
        helper(root->left, level+1, result);
        helper(root->right, level+1, result);
    }
};

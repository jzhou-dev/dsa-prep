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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;
        helper(root, result, level);
        return result;
    }   
    void helper(TreeNode* root, vector<int>& result, int level) {
        if (!root) {
            return;
        }
        if (level > result.size()-1) {
            result.push_back(root->val);
        } else {
            result[level] = root->val;
        }

        helper(root->left, result, level+1);
        helper(root->right, result, level+1);
    }
};

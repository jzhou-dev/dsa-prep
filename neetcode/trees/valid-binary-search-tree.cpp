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
    bool isValidBST(TreeNode* root) {
        return helper(root, {INT_MIN, INT_MAX});
    }
    bool helper(TreeNode* root, pair<int, int> interval) {
        if (!root) {
            return true;
        }
        if (root->val <= interval.first || root->val >= interval.second) {
            return false;
        }
        return helper(root->left, {interval.first, root->val}) && helper(root->right, {root->val, interval.second});
    }
};

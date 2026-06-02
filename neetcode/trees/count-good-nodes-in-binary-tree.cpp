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
    int maxVal = INT_MIN;
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int result = 0;
        int prevMax = maxVal;
        maxVal = max(maxVal, root->val);
        if (root->val >= maxVal) {
            result = 1 + goodNodes(root->left) + goodNodes(root->right);
        } else {
            result = goodNodes(root->left) + goodNodes(root->right);
        }
        maxVal = prevMax;
        return result;
    }
};

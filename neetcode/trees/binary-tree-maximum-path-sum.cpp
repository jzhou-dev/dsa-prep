#include "leet.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = root->val;
        maxPathSum(root, result);
        return result;
    }
    int maxPathSum(TreeNode* root, int& result) {
        if (!root) {
            return 0;
        }
        int left = max(maxPathSum(root->left, result), 0);
        int right = max(maxPathSum(root->right, result), 0);
        result = max(result, left + right + root->val);
        return root->val + max(left, right);
    }
};
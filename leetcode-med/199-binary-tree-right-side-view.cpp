#include "leet.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result = {0};
        int depth = 0;
        helper(root, result, depth);
        return result;
    }
    void helper(TreeNode* root, vector<int>& result, int depth) {
        if (root == nullptr) {
            return;
        }
        if (result.size() - 1 < depth) {
            result.push_back(root->val);
        } else {
            result[depth] = root->val;
        }
        helper(root->left, result, depth+1);
        helper(root->right, result, depth+1);
    }
};
#include "leet.h"



class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        set<int> freq;
        return helper(root, &freq);
    }
    int helper(TreeNode* root, set<int>* freq) {
        int result = 0;
        if (root == NULL) {
            return 0;
        }
        if (freq->find(root->val) == freq->end()) {
            freq->insert(root->val);
        } else {
            freq->erase(root->val);
        }

        if (root->left == NULL && root->right == NULL){
            if (freq->size() <= 1) {
                result = 1;
            } else {
                result = 0;
            }
        } else {
            int left = helper(root->left, freq);
            int right = helper(root->right, freq);
            result = left + right;
        }
        if (freq->find(root->val) == freq->end()) {
            freq->insert(root->val);
        } else {
            freq->erase(root->val);
        }
        return result;
    }
};
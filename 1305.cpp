#include "leet.h"

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        stack<int> r1;
        stack<int> r2;
        helper(root1, &r1);
        helper(root2, &r2);
        while (r1.size() > 0 || r2.size() > 0) {
            if (r1.size() == 0) {
                result.push_back(r2.top());
                r2.pop();
                continue;
            } else if (r2.size() == 0) {
                result.push_back(r1.top());
                r1.pop();
                continue;
            }
            if (r1.top() < r2.top()) {
                result.push_back(r1.top());
                r1.pop();
            } else {
                result.push_back(r2.top());
                r2.pop();
            }

        }
        return result;
    }
    void helper(TreeNode* root, stack<int>* st) {
        if (root == NULL) {
            return;
        }
        helper(root->right, st);
        st->push(root->val);
        helper(root->left, st);
    }
};
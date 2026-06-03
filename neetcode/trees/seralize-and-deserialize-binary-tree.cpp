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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> nums;
        string result = "";
        root ? nums.push(root) : nums.push(nullptr);
        while (!nums.empty()) {
            vector<TreeNode*> temp;
            while(!nums.empty()) {
                TreeNode* node = nums.front();
                if (node) {
                    result += to_string(node->val);
                    node->left ? temp.push_back(node->left) : temp.push_back(nullptr);
                    node->right ? temp.push_back(node->right) : temp.push_back(nullptr);
                } else {
                    result += '\0';
                }
                nums.pop();
            }
            for (int i = 0; i < temp.size(); i++) {
                nums.push(temp[i]);
            }
        }
        int i = result.size()-1;
        while (i >= 1 && result[i] == '\0') {
            result.pop_back();
            i--;
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize(data, 1);
    }
    TreeNode* deserialize(string data, long long i) {
        if (i > data.size() || data[i-1] == '\0') {
            return nullptr;
        }
        TreeNode* root = new TreeNode(data[i-1] - '0');
        root->left = deserialize(data, i * 2);
        root->right = deserialize(data, i * 2 + 1);
        return root;
    }
};

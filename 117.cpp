#include "leet.h"

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<Node*> lastNodes = {nullptr};
        int depth = 0;
        helper(root, lastNodes, depth);
        return root;

    }
    void helper(Node* root, vector<Node*>& lastNodes, int depth) {
        if (root == nullptr) {
            return;
        }
        if (lastNodes.size()-1 < depth) {
            lastNodes.push_back(root);
        } else {
            if (lastNodes[depth] != nullptr) {
                lastNodes[depth]->next = root;
            }
            lastNodes[depth] = root;
        }
        helper(root->left, lastNodes, depth+1);
        helper(root->right, lastNodes, depth+1);
    }
    
};      

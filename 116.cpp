#include "leet.h"
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        queue<Node*> bfs;
        bfs.push(root);
        Node* last = root;
        while (bfs.size() > 0) {
            Node* temp = bfs.front();
            bfs.pop();
            if (temp->left && temp->right) {
                bfs.push(temp->left);
                bfs.push(temp->right);
            } 
            if (bfs.size() == 0 || temp == root) {
                temp->next = nullptr;
            } else if (temp == last->right) {
                temp->next = nullptr;
                last = temp;
            }
            else {
                temp->next = bfs.front();
            }
        }
        return root;
    }
};
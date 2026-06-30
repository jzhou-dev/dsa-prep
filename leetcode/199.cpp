#include "../leet.h"

class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> result;
    rightSideView(root, result, 0);
    return result;
  }
  void rightSideView(TreeNode *root, std::vector<int> &nodes, int index) {
    if (!root) {
      return;
    }
    if (index + 1 > nodes.size()) {
      nodes.push_back(root->val);
    } else {
      nodes[index] = root->val;
    }
    rightSideView(root->left, nodes, index + 1);
    rightSideView(root->right, nodes, index + 1);
  }
};

class Solution2 {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::queue<TreeNode *> queue;
    std::vector<int> result;
    if (root) {
      queue.push(root);
    }
    while (!queue.empty()) {
      int len = queue.size();
      for (int i = 0; i < len; ++i) {
        if (queue.front()->left) {
          queue.push(queue.front()->left);
        }
        if (queue.front()->right) {
          queue.push(queue.front()->right);
        }
        if (i == len - 1) {
          result.push_back(queue.front()->val);
        }
        queue.pop();
      }
    }
    return result;
  }
};

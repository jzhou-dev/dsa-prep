#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> result;
    levelOrder(root, result, 0);
    return result;
  }
  void levelOrder(TreeNode *root, std::vector<std::vector<int>> &result,
                  int index) {
    if (!root) {
      return;
    }
    if (index + 1 > result.size()) {
      result.push_back({root->val});
    } else {
      result[index].push_back(root->val);
    }
    levelOrder(root->left, result, index + 1);
    levelOrder(root->right, result, index + 1);
  }
};

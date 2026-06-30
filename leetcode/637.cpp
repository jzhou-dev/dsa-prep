#include "../leet.h"

class Solution {
public:
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::queue<TreeNode *> queue;
    std::vector<double> result;
    queue.push(root);
    while (!queue.empty()) {
      int len = queue.size();
      double total = 0;
      for (int i = 0; i < len; ++i) {
        total += queue.front()->val;
        if (queue.front()->left) {
          queue.push(queue.front()->left);
        }
        if (queue.front()->right) {
          queue.push(queue.front()->right);
        }
        queue.pop();
      }
      result.push_back(total / len);
    }
    return result;
  }
};

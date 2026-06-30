#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::queue<TreeNode *> queue;
    std::vector<std::vector<int>> result;
    if (root) {
      queue.push(root);
    }
    int index = 0;
    while (!queue.empty()) {
      int len = queue.size();
      std::vector<int> level(len);
      bool reverse = index % 2 == 1;
      for (int i = 0; i < len; ++i) {
        if (reverse) {
          level[len - 1 - i] = queue.front()->val;
        } else {
          level[i] = queue.front()->val;
        }
        if (queue.front()->left) {
          queue.push(queue.front()->left);
        }
        if (queue.front()->right) {
          queue.push(queue.front()->right);
        }
        queue.pop();
      }
      result.push_back(level);
      index++;
    }
    return result;
  }
};

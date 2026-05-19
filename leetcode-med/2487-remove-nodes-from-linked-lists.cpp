#include "leet.h"
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* curr = head->next;
        ListNode* result = head;
        nodes.push(head);
        while (curr) {
            while (nodes.size() > 0 && nodes.top()->val < curr->val) {
                nodes.pop();
            }
            if (nodes.size() == 0) {
                result = curr;
            } else {
                nodes.top()->next = curr;
            }
            nodes.push(curr);
            curr = curr->next;
        }
        return result;
        
    }
};
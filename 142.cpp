#include "leet.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> nodes;
        while (head) {
            if (nodes.find(head) != nodes.end()) {
                return head;
            }
            nodes.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
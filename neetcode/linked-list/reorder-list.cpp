#include "leet.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < (len-1) / 2; i++) {
            curr = curr->next;
        }
        ListNode* curr2 = curr->next;
        curr->next = nullptr;
        ListNode* prev = nullptr;
        while (curr2) {
            ListNode* temp = curr2->next;
            curr2->next = prev;
            prev = curr2;
            curr2 = temp;
        }

        curr = head;
        while (prev) {
            ListNode* temp = curr->next;
            ListNode* temp2 = prev->next;
            curr->next = prev;
            prev->next = temp;
            curr = temp;
            prev = temp2;
        }

    }
};

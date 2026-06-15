#include "leet.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        } 
        vector<ListNode*> result;
        if (len < k) {
            while (k > 0) {
                if (head) {
                    ListNode* temp = head->next;
                    result.push_back(head);
                    head->next = nullptr;
                    head = temp;
                } else {
                    result.push_back(nullptr);
                }
                k--;
            }
        } else {
            int part = len / k;
            int extra = len % k;
            while (k > 0) {
                result.push_back(head);
                int curr_part = part;
                if (extra) {
                    curr_part++;
                    extra--;
                } 
                for (int i = 0; i < curr_part - 1; i++) {
                    head = head->next;
                }
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                k--;
            }
        }
        return result;
    }
};
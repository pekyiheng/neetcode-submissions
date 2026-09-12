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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* end = head;

        for (int i = 0; i < n; ++i) {
            end = end->next;
        }

        if (end == nullptr) {
            return head->next;
        }

        while (end->next) {
            front = front->next;
            end = end->next;
        }

        auto tmp = front->next;
        front->next = tmp->next;
        tmp->next = nullptr;

        return head;
    }
};

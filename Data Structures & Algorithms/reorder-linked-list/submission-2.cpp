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
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        auto cur = slow;
        auto nextl = cur->next;
        while (cur) {
            nextl = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextl;
        }

        bool useRev = true;
        cur = head;
        ListNode* tmp;
        while (prev && cur) {
            if (useRev) {
                tmp = cur;
                cur = cur->next;
                tmp->next = prev;
            } else {
                tmp = prev;
                prev = prev->next;
                tmp->next = cur;
            }
            useRev = !useRev;
        }

        if (prev) {
            prev->next = nullptr;
        } else {
            cur->next = nullptr;
        }
        

    }
};

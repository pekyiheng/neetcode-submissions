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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        ListNode* res = nullptr;
        ListNode* next = nullptr;

        if (list1->val < list2->val) {
            res = list1;
            next = list2;
        } else {
            res = list2;
            next = list1;
        }

        ListNode* cur = res;
        while (next != nullptr) {
            if (cur->next == nullptr) {
                cur->next = next;
                next = nullptr;
            } else if (cur->next->val < next->val) {
                cur = cur->next;
            } else {
                auto tmp = next;
                next = cur->next;
                cur->next = tmp;
                cur = cur->next;
            }
        }

        return res;
    }
};

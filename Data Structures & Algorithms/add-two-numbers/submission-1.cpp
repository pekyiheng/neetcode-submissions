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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = (l1->val + l2->val);
        int v = s % 10;
        int carry = s / 10;
        ListNode* res = new ListNode(v);
        auto prev = res;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 || l2) {
            int a = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            int b = 0;
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }

            int sum = carry + a + b;

            prev->next = new ListNode(sum % 10);
            carry = sum / 10;
            prev = prev->next;
            
        }

        if (carry) {prev->next = new ListNode(carry);}
        return res;
    }
};

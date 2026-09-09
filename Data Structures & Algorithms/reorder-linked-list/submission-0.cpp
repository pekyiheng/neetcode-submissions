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
        std::vector<ListNode*> v;
        v.reserve(1000);
        int i = 0;
        while (head) {
            v[i] = head;
            ++i;
            head = head->next;
        }
        --i;
        int l = 0;
        auto cur = v[0];
        bool useBack = true;
        int k = 0;
        while (l < i) {
            if (useBack) {
                v[l]->next = v[i];
                --i;
                
            } else {                
                v[i+1]->next = v[l+1];
                
                ++l;
            }
            cur = cur->next;
            useBack = !useBack;
        }
        cur->next = nullptr;
    }
};

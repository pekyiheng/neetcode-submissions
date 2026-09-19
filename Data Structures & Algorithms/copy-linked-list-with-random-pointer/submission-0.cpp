/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        std::unordered_map<Node*, int> m_in;
        std::vector<Node*> m_out;
        auto cur = head;
        auto res = new Node(head->val);
        Node* prev = res;
        m_out.push_back(res);
        m_in[head] = 0;
        int k = 1;
        cur = cur->next;

        while (cur) {
            auto tmp = new Node(cur->val);
            prev->next = tmp;
            m_in[cur] = k;
            m_out.push_back(tmp);
            prev = tmp;
            ++k;
            cur = cur->next;
        }
        
        cur = head;
        auto curNew = res;
        while (cur) {
            if (cur->random) {
                int id = m_in[cur->random];
                curNew->random = m_out[id];
            }
            
            curNew = curNew->next;
            cur = cur->next;
        }
        
        return res;
    }
};

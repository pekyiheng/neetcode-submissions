class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, vector<int>> pq;
        for (int s : stones) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int r = std::abs(a - b);
            if (r > 0) { pq.push(r); }
        }
        if (pq.size() > 0) { return pq.top(); }
        return 0;
    }
};

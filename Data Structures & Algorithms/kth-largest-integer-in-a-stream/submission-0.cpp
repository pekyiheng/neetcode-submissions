class KthLargest {
private:

public:
    int m_k;
    std::priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) : m_k(k) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > m_k) {
            pq.pop();
        }
        return pq.top();
    }
};

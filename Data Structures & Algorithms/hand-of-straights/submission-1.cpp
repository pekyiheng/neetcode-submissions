class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::unordered_map<int, int> m;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        if (hand.size() % groupSize != 0) {
            return false;
        }

        int k = hand.size() / groupSize;

        for (auto c : hand) {
            if (!m[c]) {
                pq.push(c);
                m[c] = 1;
            } else {
                m[c]++;
            }
        }

        while (k > 0) {
            while (!pq.empty() && m[pq.top()] < 1) {
                pq.pop();
            }

            int j = pq.top();
            for (int i = j; i < j + groupSize; ++i) {
                if (!m[i] || m[i] < 1) {
                    return false;
                }
                m[i]--;
            }
            --k;

           
        }

        return true;
    }
};

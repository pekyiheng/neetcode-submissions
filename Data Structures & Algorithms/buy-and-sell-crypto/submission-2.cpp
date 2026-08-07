class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int b = 0, s = 1;
        int maxp = 0;

        while (b < prices.size()) {
            maxp = std::max(maxp, prices[s] - prices[b]);
            if (s+1 < prices.size() && (b+1 >= s || prices[s] < prices[s+1])) {
                ++s;
            } else if (b+1 < prices.size() && prices[b+1] < prices[b]) {
                ++b;
            } else if (s+1 < prices.size()) {
                ++s;
            } else {
                ++b;
            }
        }

        return maxp;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        std::map<int, int, std::greater<int>> m;
        m[0] = 0;

        for (int i = coins.size() - 1; i >= 0; --i) {
            int c = coins[i];
            // std::cout << "------ \n";
            for (auto v : m) {
                int sum = v.first;
                int ccount = v.second;
                // std::cout << sum << "\n";
                while (sum+c <= amount) {
                    sum += c;
                    ccount++;
                    if (!m.contains(sum) || m[sum] > ccount) {
                        m[sum] = ccount;
                    }
                }
            }
        }

        return m.contains(amount)
                ? m[amount]
                : -1;
    }


};

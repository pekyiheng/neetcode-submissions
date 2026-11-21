class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int t = sum / 2;
        vector<vector<int>> check_con(t+1);
        vector<bool> dp(t+1, false);
        dp[0] = true;
        check_con[0] = nums;

        for (int i = 0; i <= t; ++i) {
            if (!dp[i]) continue;
            auto& l_nums = check_con[i];
            for (int j = l_nums.size() - 1; j >= 0; --j) {
                int n = l_nums[j];
                if (n + i > t) continue;
                vector<int> v = l_nums;
                v.erase(v.begin() + j);
                dp[i+n] = true;
                check_con[i+n] = move(v);
                
            }
            // std::cout << i << " : " << dp[i] << "\n";
            // std::cout << "contents:\n";
            // for (auto s : check_con[i]) {
            //     std::cout << s << "n";
            // }
            
        }
        return dp[t];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size() - 1]  = 1;
        int res = 1;

        for (int i = nums.size() - 2; i >= 0; --i) {
            int n = nums[i];
            int lmax = 1;
            for (int k = i+1; k < nums.size(); ++k) {
                if (n < nums[k]) {
                    lmax = max(lmax, dp[k] + 1);
                }  
            }
            dp[i] = lmax;
            res = max(res, lmax);

            std::cout << dp[i] << "\n";
        }

        return res;

    }
};

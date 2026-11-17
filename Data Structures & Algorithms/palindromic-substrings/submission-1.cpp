class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));

        for (int r = 0; r < s.size(); ++r) {
            for (int l = 0; l <= r; ++l) {
                if (s[l] != s[r]) {
                    continue;
                }
                if (((r - l) < 3) || dp[l+1][r-1]) {
                    ++res;
                    dp[l][r] = true;
                } 
            }
        }

        return res;
    }
};

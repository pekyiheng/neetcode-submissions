class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            bool p = false;
            for (auto& d : wordDict) {
                int dl = d.size();
                if (dl > i) continue;
                if (d == s.substr(i - dl, dl) && dp[i - dl]) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};

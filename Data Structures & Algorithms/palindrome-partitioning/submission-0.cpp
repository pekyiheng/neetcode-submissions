class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substr;
        dfs(res, s, 0, substr);

        return res;

    }

    void dfs(vector<vector<string>>& res, string& s, int idx, vector<string>& substr) {

        if (idx == s.size()) {
            res.push_back(substr);
            return;
        }
        string str = "";
        for (int i = idx; i < s.size(); ++i) {
            str += s[i];
            if (isPalindromic(str)) {
                substr.push_back(str);
                dfs(res, s, i+1, substr);
                substr.pop_back();
            }
        }
    }

    bool isPalindromic(string& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
};

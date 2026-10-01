class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = {};
        string substr = "";
        dfs(res, n, substr, 0);
        return res;
    }

    void dfs(vector<string>& res, int d, string& substr, int open) {

        if (d == 0 && open == 0) {
            res.push_back(substr);
            return;
        }

        if (open > 0) {
            substr += ")";
            dfs(res, d, substr, open-1);
            substr.pop_back();
        }

        if (d > 0) {
            substr += "(";
            dfs(res, d-1, substr, open+1);
            substr.pop_back();
        }
        
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};
        vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        dfs(res, candidates, subset, 0, target);
       
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int>& subset, int idx, int remaining) {

        if (remaining == 0) {
            res.push_back(subset);
            return;
        }

        if (idx >= candidates.size() || remaining < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }

            subset.push_back(candidates[i]);
            dfs(res, candidates, subset, i+1, remaining - candidates[i]);
            subset.pop_back();
        }

    }
};

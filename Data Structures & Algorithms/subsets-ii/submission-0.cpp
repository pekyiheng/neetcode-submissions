class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> subset = {};
        std::sort(nums.begin(), nums.end());
        dfs(res, nums, subset, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, int idx) {
        res.push_back(subset);
        if (idx >= nums.size()) {
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            subset.push_back(nums[i]);
            dfs(res, nums, subset, i+1);
            subset.pop_back();
        }
        
    }
};

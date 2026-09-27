class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> ss = {};

        dfs(res, ss, 0, nums, 0, target);

        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& subset, int sum, vector<int>& nums, int i, int t) {
        if (sum > t || i >= nums.size()) {
            return;
        }
        if (sum == t) {
            res.push_back(subset);
            return;
        }
        //push cur number again
        subset.push_back(nums[i]);
        dfs(res, subset, sum + nums[i], nums, i, t);
        subset.pop_back();
        //push next number
        dfs(res, subset, sum, nums, i+1, t);

    }
};

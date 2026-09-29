class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        vector<bool> used(nums.size(), false);

        recurse(res, nums, subset, used);
        return res;
    }

    void recurse(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, vector<bool>& used) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) { continue; }

            subset.push_back(nums[i]);
            used[i] = true;
            recurse(res, nums, subset, used);
            subset.pop_back();
            used[i] = false;
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        recurse(res, nums, subset, 0);
        return res;
    }

    void recurse(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, int mask) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (mask & (1 << i)) { continue; }

            subset.push_back(nums[i]);
            recurse(res, nums, subset, mask | (1 << i));
            subset.pop_back();

        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        set<int> idxPresent;

        recurse(res, nums, subset, idxPresent, 0);
        return res;
    }

    void recurse(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, set<int>& idxPresent, int idx) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            auto p = idxPresent.insert(i);
            if (!p.second) {
                continue;
            }
            subset.push_back(nums[i]);
            recurse(res, nums, subset, idxPresent, i+1);
            subset.pop_back();
            idxPresent.erase(i);
        }
    }
};

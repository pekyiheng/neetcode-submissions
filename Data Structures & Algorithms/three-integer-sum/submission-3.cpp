class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::set<vector<int>> s;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int l = 0;
            int r = nums.size() - 1;
            while (l < r) {
                if (l == i) {
                    ++l;
                }
                if (r == i) {
                    --r;
                }

                if (l >= r) {
                    break;
                }

                int sum = -(nums[l] + nums[r]);
                if (sum == nums[i]) {
                    vector<int> v = {nums[l], nums[r], nums[i]};
                    std::sort(v.begin(), v.end());
                    s.insert(v);
                    ++l;
                    
                } else if (sum > nums[i]) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        for (auto& x : s) {
            res.push_back(x);
        }
        return res;
    }
};

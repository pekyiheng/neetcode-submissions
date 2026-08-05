class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {continue;}
            int l = i+1;
            int r = nums.size() - 1;
            while (l < r) {
                // if ((r < nums.size() - 1) && nums[r] == nums[r+1]) {
                //     --r;
                //     continue;
                // }
                if (l >= r) {
                    break;
                }

                int sum = -(nums[l] + nums[r]);
                if (sum == nums[i]) {
                    res.push_back({nums[l], nums[r], nums[i]});
                    ++l;
                    while ((l < nums.size() - 1) && nums[l] == nums[l-1]) {
                        ++l;
                    }
                    
                } else if (sum > nums[i]) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return res;
    }
};

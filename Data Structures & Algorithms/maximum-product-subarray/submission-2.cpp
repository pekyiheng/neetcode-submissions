class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int acc1 = res;
        for (int i = 1; i < nums.size(); ++i) {
            res = std::max(res, nums[i]);
            if (nums[i] != 0) {
                acc1 *= nums[i];
                res = std::max(res, acc1);
            } else {
                acc1 = 1;
            }
        }

        int res2 = nums[nums.size() - 1];
        int acc2 = res2;
        for (int i = nums.size() - 2; i >= 0; --i) {
            res2 = std::max(res2, nums[i]);
            if (nums[i] != 0) {
                acc2 *= nums[i];
                res2 = std::max(res2, acc2);
            } else {
                acc2 = 1;
            }
        }

        return std::max(res, res2);
    }
};

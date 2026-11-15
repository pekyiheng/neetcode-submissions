class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            int n = nums[i];
            int tmp = std::max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        int ans1 = std::max(rob1, rob2);
        rob1 = 0;
        rob2 = 0;

        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            int tmp = std::max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        return std::max(ans1, max(rob1, rob2));
    }
};

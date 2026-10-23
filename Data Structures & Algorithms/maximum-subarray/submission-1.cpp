class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int highest = nums[0];

        for (int n : nums) {
            if (sum < 0) {
                sum = n;
            } else {
                sum += n;
            }
            highest = std::max(highest, sum);
        }

        return highest;

    }
};

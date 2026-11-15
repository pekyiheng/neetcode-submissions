class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;
        int rob3 = 0;
        int rob4 = 0;

        if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (i != nums.size() - 1) {
                int tmp = std::max(rob1 + n, rob2);
                rob1 = rob2;
                rob2 = tmp;
            }

            if (i == 0) {
                continue;
            }

            int tmp = std::max(rob3 + n, rob4);
            rob3 = rob4;
            rob4 = tmp;
            
        }


        return std::max(rob1, max(rob2, max(rob3, rob4)));
    }
};

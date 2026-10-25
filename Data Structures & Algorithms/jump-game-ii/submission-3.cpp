class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int i = nums.size() - 2;
        while (i >= 0) {
            int minVal = nums.size();
            
            for (int j = nums[i]; j > 0; --j) {
                if (i+j >= nums.size() - 1){ 
                    minVal = 1;
                } else {
                    minVal = min(minVal, nums[i+j] + 1);
                }
            }
            nums[i] = minVal;
            --i;
        }
        
        return nums[0];
    }
};

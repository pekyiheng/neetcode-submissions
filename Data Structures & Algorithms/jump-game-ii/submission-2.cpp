class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        vector<int> res(nums.size());
        std::cout << "test";
        int i = nums.size() - 2;
        while (i >= 0) {
            int minVal = nums.size();
            
            for (int j = nums[i]; j > 0; --j) {
                if (i+j >= nums.size() - 1){ 
                    minVal = 1;
                } else {
                    minVal = min(minVal, res[i+j] + 1);
                }
            }
            res[i] = minVal;
            --i;
        }
        
        return res[0];
    }
};

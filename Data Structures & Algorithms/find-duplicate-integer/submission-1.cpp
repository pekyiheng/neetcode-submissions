class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> bm((n/32) + 1, 0);

        for (int num : nums) {
            int id = num / 32;
            int b = num % 32;
            if (bm[id] >> b & 1) {
                return num;
            } else {
                bm[id] |= (1 << b);
            }
        }
        return 1;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int highest = 0;
        unordered_map<int, int> m;

        for (int num : nums) {
            if (m[num]) {
                continue;
            }
            int cur = 1;
            if (m[num - 1]) {
                cur += m[num -1];
            }

            m[num] = cur;

            while (m[++num] > 0) {
                ++cur;
                m[num] = cur;
            }

            if (cur > highest) {
                highest = cur;
            }
        }

        return highest;
    }
};

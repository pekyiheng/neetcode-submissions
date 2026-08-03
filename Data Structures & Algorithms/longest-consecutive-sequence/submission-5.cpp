class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int highest = 0;

        for (int num : s) {
            if (s.count(num - 1)) continue; 

            int length = 1;
            while (s.count(num + length)) {
                length++;
            }
            highest = max(highest, length);
        }

        return highest;
    }
};
